#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    TreeNode *left, *right;
    int val;
    TreeNode(int x){
        val = x;
    }
};
vector<int> res;
vector<int> leftBoundary(TreeNode* root){
    /* complete the code */
    if(!root) return res;

    res.push_back(root->val);
    if(root->left) return leftBoundary(root->left);
    else return leftBoundary(root->right);
}
vector<int> rightBoundary(TreeNode* root){
    /* complete the code */
    if(!root) return res;

    res.push_back(root->val);
    if(root->right) return rightBoundary(root->right);
    else return rightBoundary(root->left);
}
vector<int> leaves(TreeNode* root){
    /* complete the code */
    if(!root) return res;
    if(!root->left && !root->left){
        res.push_back(root->val);
        return res;
    }
    if(root->left) leaves(root->left);
    if(root->right) leaves(root->right);
    return res;
}

vector<int> boundaryTraversal(TreeNode* root){
    vector<int> dummy;
    if (root == NULL)
        return dummy;
    vector<int> ans;
    ans.push_back(root->val);
    vector<int> l = leftBoundary(root->left);
    ans.insert(ans.end(), l.begin(), l.end());
    res.clear();
    vector<int> lleaves = leaves(root->left);
    ans.insert(ans.end(), lleaves.begin(), lleaves.end());
    res.clear();
    vector<int> rleaves = leaves(root->right);
    ans.insert(ans.end(), rleaves.begin(), rleaves.end());
    res.clear();
    vector<int> r = rightBoundary(root->right);
    ans.insert(ans.end(), r.begin(), r.end());
    /* complete the code */
    return ans;
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
    cout << "output begins" << endl;
    vector<int> FinalRes = boundaryTraversal(root);
    unordered_set<int> mp;
    for(auto i : FinalRes){
        if(mp.find(i) == mp.end())
            cout << i <<" ";
        mp.insert(i);
    }
    return 0;
}