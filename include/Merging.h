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

    vector<KpletClass::KpletList> basic_merge(vector<KpletClass::Kplet> &kplets);
    vector<KpletClass::KpletList> within_order_iterative(vector<KpletClass::KpletList> kpletlists);
    
}

#endif /* MERGING_H */

