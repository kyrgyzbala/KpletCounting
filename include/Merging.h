/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Merging.h
 * Author: hudaiber
 *
 * Created on February 2, 2016, 5:17 PM
 */

#ifndef MERGING_H
#define MERGING_H

using namespace std;

#include<vector>

namespace merging {
    
    class Parameters{
    public:
        float basic_loci_thr;
        float iterative_loci_thr;
        Parameters(float basic_loci_thr, float iterative_loci_thr):
                basic_loci_thr(basic_loci_thr), iterative_loci_thr(iterative_loci_thr){}
    };
    
    vector<KpletClass::KpletList_ind> basic_merge(vector<KpletClass::Kplet_ind> &kplets, Parameters &params);
    vector<KpletClass::KpletList_ind> within_order_iterative(vector<KpletClass::KpletList_ind> kpletlists, Parameters &params);
    
    vector<KpletClass::KpletList> basic_merge(vector<KpletClass::Kplet> &kplets, Parameters &params);
    vector<KpletClass::KpletList> within_order_iterative(vector<KpletClass::KpletList> kpletlists, Parameters &params);
    
}

#endif /* MERGING_H */

