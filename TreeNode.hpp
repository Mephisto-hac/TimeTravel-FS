#ifndef TREENODE_HPP
#define TREENODE_HPP

#include <vector>
#include <string>
#include <ctime>
using namespace std;

struct TreeNode {
   int version_id;
    string content;
    string message; // Empty if not a snapshot
    time_t created_timestamp;
    time_t snapshot_timestamp; // Null if not a snapshot
    TreeNode* parent;
    vector<TreeNode*> children;

    TreeNode(){
        version_id=0;
        content="";
        message="";
        created_timestamp=time(0);
        snapshot_timestamp=-1;
        parent=NULL;
        children={};
    }
    TreeNode(int version_id,string content,TreeNode*parent){
        this->version_id=version_id;
        this->content=content;
        this->parent=parent;
        message="";
        created_timestamp=time(0);
        snapshot_timestamp=-1;
        children={};

    }
};

#endif