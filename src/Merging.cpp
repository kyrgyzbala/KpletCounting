/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<vector>
#include<iterator>
#include "KpletClasses.h"
#include "Merging.h"
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

bool similar_same_order(KpletClass::Kplet &kplet1, KpletClass::Kplet &kplet2) {
    
    vector<string> common_codes, common_files;
    
    set_intersection(kplet1.GetCodes().begin(), kplet1.GetCodes().end(),
            kplet2.GetCodes().begin(), kplet2.GetCodes().end(),
            back_inserter(common_codes));
    
    set_intersection(kplet1.GetFiles().begin(), kplet1.GetFiles().end(),
            kplet2.GetFiles().begin(), kplet2.GetFiles().end(),
            back_inserter(common_files));
    
    int k = kplet1.GetK();
    int num_common_codes = common_codes.size();
    float ratio_common_files = float(common_files.size()) / min(kplet1.GetFiles().size(), kplet2.GetFiles().size());
    if (ratio_common_files == 1) return true;
    if ((k == 5) && (num_common_codes == 4 && ratio_common_files > 0.9)) return true;
    else if ((k == 4) && (num_common_codes == 3 && ratio_common_files > 0.9)) return true;
    else if ((k == 3) && (num_common_codes == 2 && ratio_common_files > 0.9)) return true;
    else if ((k == 2) && (num_common_codes == 1 && ratio_common_files > 0.9)) return true;
    
    return false;
};

vector<KpletClass::KpletList> merging::basic_merge(vector<KpletClass::Kplet> &kplets) {

    vector<KpletClass::KpletList> merged_list;
    
    vector<bool> merged_out;
    vector<int> to_move;
    vector<KpletClass::Kplet *> to_move_kplets;
    set<string> to_move_files;
    unsigned int i;
    for (i = 0; i < kplets.size(); i++)merged_out.push_back(0);
    
    for (i = 0; i < kplets.size()-1; i++) {
        if (merged_out[i] == 1) continue;
        unsigned int j;
        for (j = i + 1; j < kplets.size(); j++) {
            
            if (merged_out[j] == 1) continue;
            
            if (to_move.size() == 0) to_move.push_back(i);
            
            if (similar_same_order(kplets[i], kplets[j])){
                to_move.push_back(j);
                merged_out[j]=1;
            }
        }
        
        for(unsigned int k=0;k<to_move.size();k++){
            to_move_kplets.push_back(&kplets[to_move[k]]);
//            to_move_files.insert(kplets[to_move[k]].GetFiles().begin(), kplets[to_move[k]].GetFiles().end());
        }

        KpletClass::KpletList kplet_list(to_move_kplets, to_move_files);
        merged_list.push_back(kplet_list);
        to_move.clear();
        to_move_kplets.clear();

    }
    
    return merged_list;

};
