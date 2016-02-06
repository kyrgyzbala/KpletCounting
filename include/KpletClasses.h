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
        set<int> profiles;
        int id;
        int count;
        set<int> files;
        
    public:
        
        Kplet(int k, set<int> profiles, int id, int count, 
                set<int> files = set<int>()): k(k), profiles(profiles), id(id), 
                count(count), files(files){}
        
        ~Kplet(){}
        
        set<int>& GetFiles() {
            return files;
        }

        void SetFiles(set<int> files) {
            this->files = files;
        }

        set<int>& GetProfiles() {
            return profiles;
        }

        void SetProfiles(set<int> profiles) {
            this->profiles = profiles;
        }
        
        int GetCount() {
            return count;
        }

        void SetCount(int count) {
            this->count = count;
        }

        int GetId() {
            return id;
        }

        void SetId(int id) {
            this->id = id;
        }

        int GetK() {
            return k;
        }

        void SetK(int k) {
            this->k = k;
        }

        
    };
    
    class KpletList{
        vector<Kplet *> kplets;
        set<int> files;
    public:
        KpletList(vector<Kplet *> kplets, set<int> files): kplets(kplets),
                files(files) {}
        
        ~KpletList(){}
        
        set<int>& GetFiles() {
            return files;
        }

        void SetFiles(set<int> files) {
            this->files = files;
        }

        vector<Kplet *> GetKplets() {
            return kplets;
        }

        void SetKplets(vector<Kplet*> kplets) {
            this->kplets = kplets;
        }
        void merge(KpletList other){
            //insert the kplets of other to this
            for(unsigned int i=0;i<other.GetKplets().size();i++){
                this->kplets.push_back(other.GetKplets()[i]);
            }
            
            set<int>::iterator it;
            for(it=other.GetFiles().begin(); it!= other.GetFiles().end(); ++it){
                this->files.insert(*it);
            }
        }
    };
    
}