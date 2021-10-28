#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val{x}{}
};

int findCity(TreeNode* root, int p, int q){
    if(!root) return -1;
    if(root->val == p or root->val == q) return root->val;
    int left = findCity(root->left, p, q);
    int right = findCity(root->right, p, q);
    if(left != -1 and right != -1) return root->val;
    else if(left) return left;
    else return right;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(4);


    root->left->right = new TreeNode(7);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(5);

    root->right->left->left = new TreeNode(8);
    root->right->left->right = new TreeNode(6);
    root->right->left->right->left = new TreeNode(9);

    cout<< endl<<findCity(root, 8, 9)<<endl;
}