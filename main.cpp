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

void processUsingMaps(string input_file, string output_file, merging::Parameters params){
    
    //Holds the grand list of files
    vector<string> files;
    unordered_map<string, unsigned int> file2ind;
    vector<string> profiles;
    unordered_map<string, unsigned int> profile2ind;
    vector<KpletClass::Kplet_ind> kplets;
    printf("Reading kplets from: %s\n", input_file.c_str());
    
    DataIO::readKpletsFromCsvBz2(input_file, kplets, files, file2ind, profiles, profile2ind);
    printf("%lu kplets read.\n", kplets.size());
    
    vector<KpletClass::KpletList_ind> kplet_merged_lists = merging::basic_merge(kplets, params);
    printf("Basic merging finished. Number of merged lists: %lu \n", kplet_merged_lists.size());
    
    kplet_merged_lists = merging::within_order_iterative(kplet_merged_lists, params);
    cout << "Iterative Merged lists size: " << kplet_merged_lists.size() << endl;
    DataIO::writeMergedListsToCsv(kplet_merged_lists, output_file);
}

//void processPlainVector(string fname, string out_name){
//    
//    vector<KpletClass::Kplet> kplets;
//    printf("Reading kplets from: %s\n", fname.c_str());
//    DataIO::readKpletsFromCsvBz2(fname, kplets);
//    printf("Done reading kplets. %d\n", kplets.size());
//    printf("%lu kplets read.\n", kplets.size());
//    vector<KpletClass::KpletList> kplet_merged_lists = merging::basic_merge(kplets);
//    printf("Basic merging finished. Number of merged lists: %lu \n", kplet_merged_lists.size());
//    kplet_merged_lists = merging::within_order_iterative(kplet_merged_lists);
//    cout << "Iterative Merged lists size: " << kplet_merged_lists.size() << endl;
//    DataIO::writeMergedListsToCsv(kplet_merged_lists, out_name);
//}

int main(int argc, char** argv) {
    
    string input_file, output_file;
    float basic_thr = 0.9;
    float iterative_thr = 0.9;
    
    if (argc<3){
        cout << "Usage: merger input_file.csv.bz2 output_file.csv basic_merging_thr=0.5 iterative_merging_thr=0.5"<< endl;
        exit(EXIT_FAILURE);
    }
    else if (argc == 4){
        basic_thr = atof(argv[3]);
    } else if (argc == 5){
        basic_thr = atof(argv[3]);
        iterative_thr = atof(argv[4]);
    }
    
    input_file = argv[1];
    output_file = argv[2];
    
    merging::Parameters params(basic_thr, iterative_thr);
    
    time_t start, end;
    double elapsed_secs;
    
    cout << "Starting using maps" << endl;
    start = clock();
    processUsingMaps(input_file, output_file, params);
    end = clock();
    elapsed_secs = double(end - start) / CLOCKS_PER_SEC;
    cout << "Elapsed time: " << elapsed_secs << endl;
    
//    cout << "Starting using vectors" << endl;
//    start = clock();
//    processPlainVector(input_file, output_file, params);
//    end = clock();
//    elapsed_secs = double(end - start) / CLOCKS_PER_SEC;
//    cout << "Elapsed time: " << elapsed_secs << endl;
    
    cout << "Done!" << endl;
    
    return EXIT_SUCCESS;
}

