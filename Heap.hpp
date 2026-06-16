#include<iostream>
#include <string>
#include <ctime>
using namespace std;

struct HeapNode {
    string filename;
    time_t priority;

    HeapNode(string filename, time_t priority){
        this->filename=filename;
        this->priority=priority;
       
    }
};

class Heap {
    HeapNode* arr[100];
    int size;

    public:
    Heap(){
        size=0;
    }
    void insertion(HeapNode* node){
        arr[size]=node;
        int i=size;
        size++;
        HeapNode* temp=node;
        while(i>0&&temp->priority>arr[(i-1)/2]->priority){
            arr[i]=arr[(i-1)/2];
            i=(i-1)/2;
        }
        arr[i]=temp;
    }
    HeapNode* deletion(){
        HeapNode* x=arr[0];
        arr[0]=arr[size-1];
         size--;
       
        int i=0;
        int j=2*i+1;
        while(j<size){
            if(j<size-1&&arr[j]->priority<arr[j+1]->priority)j++;
            if(arr[j]->priority>arr[i]->priority){
                swap(arr[j],arr[i]);
                i=j;
                j=2*i+1;
            }
            else break;
        }
       
        return x;
    }


    int getSize(){
        return size;
    }
};