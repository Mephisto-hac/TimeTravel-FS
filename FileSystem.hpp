#ifndef FILESYSTEM_HPP
#define FILESYSTEM_HPP

#include "File.hpp"
#include "Heap.hpp"
#include <map>
#include <string>
#include <iostream>

class FileSystem {
    map<string, File*> files;

public:
   void createFile(string filename){
    if(files.find(filename)==files.end()){
        File* newfile=new File(filename);
        files[filename]=newfile;
        cout << "File created successfully." << endl;
    }
    else {
        cout << "File already exists." << endl;
    }
   }



   void readFile(string filename){
    if(files.find(filename)==files.end()){
        cout << "File not found."<< endl;
        return;
    }
    else{
       File* curr=files[filename];
       if(curr->active_version->content==""){
        cout << "File is empty."<< endl;
       }
       else {
        cout <<curr->active_version->content << endl;
       }
    }
   }

   void insertFile(string filename,string content){
    if(files.find(filename)==files.end()){
        cout <<"File not found."<< endl;
        return;
    }
     File* curr=files[filename];
     if(curr->active_version->snapshot_timestamp!=-1){
        int id=curr->total_versions;
        string newContent= curr->active_version->content+" "+content;
        
        TreeNode* newNode=new TreeNode(id,newContent,curr->active_version);
        curr->version_map.insert(id,newNode);

        curr->active_version->children.push_back(newNode);
        curr->total_versions=curr->total_versions+1;
        curr->active_version=newNode;


     }
     else{
        curr->active_version->content+=" "+content;
     }
     curr->last_modified=time(0);

   }

   void updateFile(string filename,string content){
     if(files.find(filename)==files.end()){
        cout <<"File not found."<< endl;
        return;
    }
     File* curr=files[filename];
     if(curr->active_version->snapshot_timestamp!=-1){
        int id=curr->total_versions;
        string newContent= content;
        
        TreeNode* newNode=new TreeNode(id,newContent,curr->active_version);
        curr->version_map.insert(id,newNode);

        curr->active_version->children.push_back(newNode);
        curr->total_versions=curr->total_versions+1;
        curr->active_version=newNode;


     }
     else{
        curr->active_version->content=content;
     }
     curr->last_modified=time(0);

   }

   void snapshotFile(string filename,string message){
     if(files.find(filename)==files.end()){
        cout <<"File not found."<< endl;
        return;
    }
    File* curr=files[filename];
    if(curr->active_version->snapshot_timestamp!=-1){
        cout <<"Already a snapshot." << endl;
        return;
    }
    else{
        
        curr->active_version->snapshot_timestamp=time(0);
        curr->active_version->message=message;
        curr->last_modified=time(0);

    }
   }

   void roolbackFile(string filename,int id){
    if(files.find(filename)==files.end()){
        cout <<"File not found."<< endl;
        return;
    }
    File* curr=files[filename];
   
    
    if(id!=-1){
        TreeNode* node=curr->version_map.searching(id);
        if(node==NULL){
        cout <<"Version not found."<< endl;
        return;
        }
        curr->active_version=node;
        cout << "Rolled back to version " << id << endl;
    }
    else{
        if(curr->active_version->parent==NULL){
            cout <<"Already at root."<< endl;
            return;
        }
        curr->active_version=curr->active_version->parent;
         cout << "Rolled back to parent version." << endl;
    }
   }

   void historyFile(string filename){
     if(files.find(filename)==files.end()){
        cout <<"File not found."<< endl;
        return;
    }
    File* curr=files[filename];
    TreeNode* node=curr->active_version;
    while(node!=NULL){
        if(node->snapshot_timestamp!=-1){
            cout << node->version_id<<" - "<<node->message<<" - ";
            string time_str = ctime(&node->snapshot_timestamp);
            cout << time_str;
        }
       node=node->parent;
    }
   }


   void recentFile(int num){
    Heap recent;
    for(auto x:files){
        string name=x.first;
        File* file= x.second;
        
        HeapNode* temp=new HeapNode(name,(time_t)file->last_modified);
        recent.insertion(temp);
    }
    for(int i=0;i<num&&recent.getSize()>0;i++){
        HeapNode* top=recent.deletion();
        cout << top->filename << endl;
    }
   }

   void biggestTree(int num){
    Heap recent;
    for(auto x:files){
        string name=x.first;
        File* file= x.second;
        
        HeapNode* temp=new HeapNode(name,(time_t)file->total_versions);
        recent.insertion(temp);
    }
    for(int i=0;i<num&&recent.getSize()>0;i++){
        HeapNode* top=recent.deletion();
        cout << top->filename << endl;
    }
    }


};

#endif