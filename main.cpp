/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: hudaiber
 *
 * Created on January 28, 2016, 4:22 PM
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <cmath>
#include "KpletClasses.h"
#include "BioClasses.h"
#include "DataIO.h"
#include "Merging.h"
#include <list>
#include<vector>
#include<unordered_map>

using namespace std;

int main(int argc, char** argv) {

    //    list<BioClass::Gene> genes;
    //    
    //    char *c = (char *)malloc(sizeof(char) * 3);
    //    
    //    BioClass::Gene *gene = new BioClass::Gene(111,"Burkholderia","NC_432342",
    //            '+',1000,2000,"arCOG1234,COG1234", "LuxR");
    //    genes.insert(genes.begin(), *gene);
    //    
    //    BioClass::Gene gene2(222,"Burkholderia","NC_432343",'-',3000,4000,
    //                        "arCOG1234,COG1234", "LuxI");
    //    genes.insert(genes.begin(), gene2);
    //    
    //    delete gene;

    //    string fname = 
    //            "/Users/hudaiber/Projects/NewSystems/data/CRISPR/datasets/cas1_2/wgs/1.pty";
    //    
    //    vector<BioClass::Gene> genes;
    //    genes = FileReader::readWGSFile(fname);
    //    cout<< "No of genes: " << genes.size() << endl;
    //    for (int i=0; i<genes.size(); i++){
    //        cout << genes[i].GetGi() << " " << genes[i].GetFrom() << " "<< genes[i].GetTo() << " ";
    //        cout << genes[i].GetGenome() <<" "<<genes[i].GetSource();
    //        cout << " " << genes[i].GetProfiles() << " " << genes[i].GetStrand() << endl;
    //    }

    string fname = "duplets.csv.bz2";
//    string fname = "/Volumes/hudaiber/Projects/KpletCounting/run_folder/duplets_seed.p.bz2";
//    string fname = argv[1];
    //    vector<string> args(argv+1,argv+argc);
    //    string fname = args[0];
//    printf("%s\t%d\n", __FILE__, __LINE__);
//    fflush(NULL);
    
    //Holds the grand list of files
    vector<string> files;
    unordered_map<string, unsigned int> file2ind;
    vector<string> profiles;
    unordered_map<string, unsigned int> profile2ind;
    vector<KpletClass::Kplet> kplets;
    
    DataIO::readKpletsFromCsvBz2(fname, kplets, files, file2ind, profiles, profile2ind);
    
    cout << "Files and file2ind sizes:" << endl;
    cout<< files.size() << endl;
    cout<< file2ind.size() << endl;
    cout << "Profiles and profile2ind sizes:" << endl;
    cout<< profiles.size() << endl;
    cout<< profile2ind.size() << endl;
//    DataIO::readKpletsFromCsvBz2(fname, &kplets, &files, &file2ind, &profiles, &profile2ind);
    
    
//    vector< KpletClass::Kplet> kplets = DataIO::readKpletsFromCsvBz2(fname);
//    vector<KpletClass::KpletList> kplet_merged_lists = merging::basic_merge(kplets);
//    cout << "Merged lists size: " << kplet_merged_lists.size() << endl;
//    kplet_merged_lists = merging::within_order_iterative(kplet_merged_lists);
//    cout << "Iterative Merged lists size: " << kplet_merged_lists.size() << endl;
    
    return EXIT_SUCCESS;
}

