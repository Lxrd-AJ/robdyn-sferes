//| This file is a part of the sferes2 framework.
//| Copyright 2009, ISIR / Universite Pierre et Marie Curie (UPMC)
//| Main contributor(s): Jean-Baptiste Mouret, mouret@isir.fr

//|
//| This software is a computer program whose purpose is to facilitate
//| experiments in evolutionary computation and evolutionary robotics.
//|
//| This software is governed by the CeCILL license under French law
//| and abiding by the rules of distribution of free software.  You
//| can use, modify and/ or redistribute the software under the terms
//| of the CeCILL license as circulated by CEA, CNRS and INRIA at the
//| following URL "http://www.cecill.info".
//|
//| As a counterpart to the access to the source code and rights to
//| copy, modify and redistribute granted by the license, users are
//| provided only with a limited warranty and the software's author,
//| the holder of the economic rights, and the successive licensors
//| have only limited liability.
//|
//| In this respect, the user's attention is drawn to the risks
//| associated with loading, using, modifying and/or developing or
//| reproducing the software by the user in light of its specific
//| status of free software, that may mean that it is complicated to
//| manipulate, and that also therefore means that it is reserved for
//| developers and experienced professionals having in-depth computer
//| knowledge. Users are therefore encouraged to load and test the
//| software's suitability as regards their requirements in conditions
//| enabling the security of their systems and/or data to be ensured
//| and, more generally, to use and operate it in the same conditions
//| as regards security.
//|
//| The fact that you are presently reading this means that you have
//| had knowledge of the CeCILL license and that you accept its terms.

#ifndef PHEN_HNN_HPP
#define PHEN_HNN_HPP

#include <map>
#include <queue>
#include <sferes/phen/indiv.hpp>
#include <modules/nn2/nn.hpp>

#include <modules/nn2/params.hpp>
#include "gen_hnn.hpp"


namespace sferes
{
namespace phen
{
// hyperneat-inspired phenotype, based on a cppn
SFERES_INDIV(Hnn, Indiv)
{
    public:
    typedef Gen gen_t;
    typedef typename Params::hnn::neuron_t neuron_t;
    typedef typename Params::hnn::connection_t connection_t;
    typedef typename nn::NN<neuron_t, connection_t> nn_t;
//    typedef typename nn_t::vertex_desc_t v_d_t;
//    typedef typename std::vector<v_d_t> layer_t;
    Hnn() : _developed(false) {}

    void develop()
    {
        if (_developed)
            return;
        _developed = true;
        this->gen().init();

        static const size_t nb_inputs  = Params::hnn::nb_inputs;
        static const size_t last_layer = Params::hnn::nb_layers - 1;
        static const size_t nb_outputs = Params::hnn::nb_outputs;
    }

    nn_t& nn() { return _nn; }
    const nn_t& nn() const { return _nn; }

    protected:
    bool _developed;

    nn_t _nn;
    //std::vector<layer_t> _layers;
};
}
}
#endif