#include "FileSystem.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){
    FileSystem fs;
    string line;
    
    while(getline(cin, line)){
       stringstream ss(line);
       string word;
       ss >> word;
       if(word=="CREATE"){
        ss >> word;
        fs.createFile(word);
       }
       else if(word=="READ"){
        ss >> word;
        fs.readFile(word);
       }
        else if(word=="INSERT"){
        ss >> word;
        string content;
        getline(ss, content);
        if(content.length() > 0){  
        content= content.substr(1);
        fs.insertFile(word,content);
       }
        else if(word=="UPDATE"){
        ss >> word;
        string content;
        getline(ss, content);
        content= content.substr(1);
        fs.updateFile(word,content);
       }
        else if(word=="SNAPSHOT"){
        ss >> word;
        string content;
        getline(ss, content);
        content= content.substr(1);
        fs.snapshotFile(word,content);
       }
        else if(word=="ROLLBACK"){
        ss >> word;
        int id=-1;
        ss >> id;
        fs.roolbackFile(word,id);
       }
        else if(word=="HISTORY"){
        ss >> word;
        fs.historyFile(word);
       }
        else if(word=="RECENT_FILES"){
        
        int num;
        ss >> num;
        fs.recentFile(num);
       }
       else if(word=="BIGGEST_TREES"){
        int num;
        ss >> num;
        fs.biggestTree(num);
       }
    }
    return 0;
}