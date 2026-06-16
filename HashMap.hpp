#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include "TreeNode.hpp"

struct HashNode {
   int key;
   TreeNode* value;
   HashNode* next;
   HashNode (int key,TreeNode* value){
    this->key=key;
    this->value=value;
    next=NULL;
   }
};

class HashMap {
   HashNode* bucket[100];
  
    
    int hash(int key) {
        return key % 100;
    }

public:
 HashMap(){
    for(int i=0;i<100;i++){
        bucket[i]=NULL;
    }
   }
   void insert(int key,TreeNode* value){
    int index=hash(key);
    HashNode* newNode=new HashNode(key,value);
    newNode->next=bucket[index];
    bucket[index]=newNode;


   }
   TreeNode* searching(int key){
    int index=hash(key);
    HashNode* curr = bucket[index];
    while(curr!=NULL){
        if(curr->key==key)return curr->value;
        curr=curr->next;
        
    }
    return NULL;
   }
    
  
};

#endif