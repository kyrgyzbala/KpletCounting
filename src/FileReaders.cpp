/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <fstream>
#include <vector>
#include <set>
#include <boost/algorithm/string.hpp>
#include "KpletClasses.h"
#include "BioClasses.h"
#include "FileReaders.h"
//#include "BioClasses.h"
#include<iostream>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/filter/bzip2.hpp>
#include <boost/iostreams/device/file.hpp>

using namespace std;

vector<BioClass::Gene> FileReader::readWGSFile(string fname) {
    
    vector<BioClass::Gene> genes;
    string line;
    ifstream fin(fname.c_str());
    
    if (fin.is_open()) {
        
        while (getline(fin, line)) {
            
            vector<string> fields;
            boost::algorithm::split(fields, line, boost::is_any_of("\t"));
            vector<string> coordinates;
            boost::algorithm::split(coordinates, fields[1], boost::is_any_of(".."));
            
            string genome, source, string, profiles, gene_name, description;
            int from, to, gi;
            char strand;
            
            gi = atoi(fields[0].c_str());
            genome = fields[3];
            source = fields[4];
            strand = fields[2].at(0);
            from = atoi(coordinates[0].c_str());
            to = atoi(coordinates[2].c_str());
            profiles = fields[6];
            gene_name = fields[8];
            description = "";
            
            BioClass::Gene *gene = new BioClass::Gene(gi, genome, source, strand,
                    from, to, profiles, gene_name, description);
            genes.push_back(*gene);
            cout << endl;
//            file_content.push_back(line);
        }
    } else {
        cerr << "Error opening file:" << fname << endl;
        exit(EXIT_FAILURE);
    }

    return genes;
};

vector<KpletClass::Kplet> FileReader::readKpletsFromCsvBz2(string fname){
    
    vector<KpletClass::Kplet> kplets;
    
    // Open the file
    boost::iostreams::file_source input_file(fname, std::ios_base::in | std::ios_base::binary);
    
    if (!input_file.is_open()){
        cerr << "Files is not opened:" << fname << endl;
    }
    
    
    // Uncompress the file with the BZ2 library and its Boost wrapper
    boost::iostreams::filtering_istream in;
    in.push(boost::iostreams::bzip2_decompressor());
    in.push(input_file);
    
    // Open the file to be read
    string line;
    
    //Skip the header line
    getline(in, line);
    vector<string> fields;
    
    int id, k, count;
    set<string> codes;
    set<string> files;
    
    while (getline(in, line)) {
        
        line = line.substr(0, line.size()-1);
        
        fields = boost::split(fields, line, boost::is_any_of(","));
        
        id = atoi(fields[0].c_str());
        k = atoi(fields[1].c_str());
        count = atoi(fields[2].c_str());
        boost::split(codes, fields[3], boost::is_any_of(" "));
        boost::split(files, fields[4], boost::is_any_of(" "));
        
        KpletClass::Kplet *kplet = new KpletClass::Kplet(k, codes, id, count, files);
        kplets.push_back(*kplet);
        delete kplet;
    }
    return kplets;
};

vector<KpletClass::Kplet> FileReader::readKpletsFromCsv(string fname){
    
    vector<KpletClass::Kplet> kplets;
    
    ifstream infile(fname.c_str());
    string line;
    
    //Skip the header line
    getline(infile, line);
    vector<string> fields;
    
    int id, k, count;
    set<string> codes;
    set<string> files;
    
    while (getline(infile, line)) {
        
        fields = boost::split(fields, line, boost::is_any_of(","));
        
        id = atoi(fields[0].c_str());
        k = atoi(fields[1].c_str());
        count = atoi(fields[2].c_str());
        boost::split(codes, fields[3], boost::is_any_of(" "));
        boost::split(files, fields[4], boost::is_any_of(" "));
        
        KpletClass::Kplet *kplet = new KpletClass::Kplet(k, codes, id, count, files);
        kplets.push_back(*kplet);
        delete kplet;
    }
    
    return kplets;
};