/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   KpletClasses.h
 * Author: hudaiber
 *
 * Created on February 1, 2016, 12:48 PM
 */
#include<string>
#include <vector>
#include <set>

using namespace std;

namespace KpletClass {

    class Kplet{
        
        int k;
        set<string> codes;
        int id;
        int count;
        set<string> files;
        
    public:
        
        Kplet(int k, set<string> codes, int id, int count, 
                set<string> files = set<string>()): k(k), codes(codes), id(id), 
                count(count), files(files){}
        
        ~Kplet(){}
        set<string>& GetCodes()  {
            return codes;
        }

        void SetCodes(set<string> codes) {
            this->codes = codes;
        }

        int GetCount() const {
            return count;
        }

        void SetCount(int count) {
            this->count = count;
        }

        set<string>& GetFiles() {
            return files;
        }

        void SetFiles(set<string> files) {
            this->files = files;
        }

        int GetId() const {
            return id;
        }

        void SetId(int id) {
            this->id = id;
        }

        int GetK() const {
            return k;
        }

        void SetK(int k) {
            this->k = k;
        }


    };
    
    class KpletList{
        vector<Kplet *> kplets;
        set<string> files;
    public:
        KpletList(vector<Kplet *> kplets, set<string> files): kplets(kplets),
                files(files) {}
        
        ~KpletList(){}
    };
    
}