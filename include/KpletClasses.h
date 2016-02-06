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
        vector<int> profiles;
        int id;
        int count;
        vector<int> files;
        
    public:
        
        Kplet(int k, vector<int> profiles, int id, int count, 
                vector<int> files = vector<int>()): k(k), profiles(profiles), id(id), 
                count(count), files(files){}
        
        ~Kplet(){}
        
        vector<int>& GetFiles() {
            return files;
        }

        void SetFiles(vector<int> files) {
            this->files = files;
        }

        vector<int>& GetProfiles() {
            return profiles;
        }

        void SetProfiles(vector<int> profiles) {
            this->profiles = profiles;
        }

    };
    
    class KpletList{
        vector<Kplet *> kplets;
        set<string> files;
    public:
        KpletList(vector<Kplet *> kplets, set<string> files): kplets(kplets),
                files(files) {}
        
        ~KpletList(){}
        
        set<string>& GetFiles() {
            return files;
        }

        void SetFiles(set<string> files) {
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
            
            set<string>::iterator it;
            for(it=other.GetFiles().begin(); it!= other.GetFiles().end(); ++it){
                this->files.insert(*it);
            }
        }
    };
    
}