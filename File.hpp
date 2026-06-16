#ifndef FILE_HPP
#define FILE_HPP

#include "TreeNode.hpp"
#include "HashMap.hpp"
#include <string>

class File {
public:
    string filename;
    TreeNode* root;
    TreeNode* active_version;
    HashMap version_map;
    int total_versions;
    time_t last_modified;

    File( string filename){
        root=new TreeNode(0,"",NULL);
       
        active_version=root;
        total_versions=1;
        root->snapshot_timestamp=time(0);
        root->message="initial snapshot";
        this->filename=filename;
        version_map.insert(0,root);
        last_modified=time(0);


    }
};

#endif