#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    TreeNode *left, *right;
    int val;
    TreeNode(int x){
        val = x;
    }
};

void helper(TreeNode* root, int k, unordered_map<int, int> &mp, int sum, int& res){
    if(root){
        if(sum+root->val == k)
            res++;
        res += mp[sum+root->val - k];
        mp[sum+root->val]++;
        helper(root->left, k, mp, sum+root->val, res);
        helper(root->right, k, mp, sum+root->val, res);
        mp[sum+root->val]--;
    }
}
int numberOfRoutes(TreeNode* root, int k){
    //use this map to store how many times a number appears
    unordered_map<int, int> mp;
    int res = 0;
    helper(root, k, mp, 0, res);
    return res;
}
int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->left->left->right = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(10);
    root->right->right->left = new TreeNode(-3);
    root->right->right->right = new TreeNode(-7);
 
    int k = 3;
    cout << "No of paths with sum equals to " <<  k
         << " are : "  << numberOfRoutes(root, k) << "\n";
    return 0;
 
}