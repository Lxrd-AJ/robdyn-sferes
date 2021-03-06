#! /usr/bin/env python
# encoding: utf-8

import os,sys
import Task,Utils
from Configure import conftest
ar_str='${AR} ${ARFLAGS} ${AR_TGT_F}${TGT} ${AR_SRC_F}${SRC}'
cls=Task.simple_task_type('static_link',ar_str,color='YELLOW',ext_in='.o',shell=False)
cls.maxjobs=1
cls.install=Utils.nada
old=cls.run
def wrap(self):
	try:os.remove(self.outputs[0].abspath(self.env))
	except OSError:pass
	return old(self)
setattr(cls,'run',wrap)
def detect(conf):
	conf.find_program('ar',var='AR')
	conf.find_program('ranlib',var='RANLIB')
	conf.env.ARFLAGS='rcs'
def find_ar(conf):
	v=conf.env
	conf.check_tool('ar')
	if not v['AR']:conf.fatal('ar is required for static libraries - not found')

conftest(find_ar)
