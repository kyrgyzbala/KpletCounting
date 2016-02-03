/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BioClasses.h
 * Author: hudaiber
 *
 * Created on January 29, 2016, 1:35 PM
 */

using namespace std;

namespace BioClass {

    class Gene {
        int gi;
        string genome;
        string source;
        char strand;
        int from;
        int to;
        string profiles;
        string gene_name;
        string description;

    public:

        Gene(int gi, string genome, string source, char strand,
                int from, int to, string profiles = "", string gene_name = "",
                string description = "") : gi(gi), genome(genome), source(source),
        strand(strand), from(from), to(to), profiles(profiles),
        gene_name(gene_name), description(description) {}
        
        ~Gene(){}

        string GetDescription() const {
            return description;
        }

        int GetFrom() const {
            return from;
        }

        string GetGene_name() const {
            return gene_name;
        }

        string GetGenome() const {
            return genome;
        }

        int GetGi() const {
            return gi;
        }

        string GetProfiles() const {
            return profiles;
        }

        string GetSource() const {
            return source;
        }

        char GetStrand() const {
            return strand;
        }

        int GetTo() const {
            return to;
        }

        void SetDescription(string description) {
            this->description = description;
        }

        void SetFrom(int from) {
            this->from = from;
        }

        void SetGene_name(string gene_name) {
            this->gene_name = gene_name;
        }

        void SetGenome(string genome) {
            this->genome = genome;
        }

        void SetGi(int gi) {
            this->gi = gi;
        }

        void SetProfiles(string profiles) {
            this->profiles = profiles;
        }

        void SetSource(string source) {
            this->source = source;
        }

        void SetStrand(char strand) {
            this->strand = strand;
        }

        void SetTo(int to) {
            this->to = to;
        }


    };

}

