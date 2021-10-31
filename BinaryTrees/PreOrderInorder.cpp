#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    TreeNode *left, *right;
    int val;
    TreeNode(int x){
        val = x;
    }
};

int preIndex=0;
TreeNode* make(vector<int> &preorder, vector<int> &inorder, int inStart, int inEnd, unordered_map<int,int> &mp){
    if(inStart>inEnd){
        return NULL;
    }
    TreeNode* temp = new TreeNode(preorder[preIndex++]);
    int inIndex = mp[temp->val];
    /*complete the code to assign subtrees to left and right of temp*/
    return temp;
}
TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
    preIndex=0;
    //this map will store the index of the in-order traversal
    unordered_map<int,int> mp;
    for(int i=0;i<inorder.size();i++){
        mp.insert(pair<int, int>(inorder[i], i));
    }
    return make(preorder,inorder,0,preorder.size()-1, mp);
}