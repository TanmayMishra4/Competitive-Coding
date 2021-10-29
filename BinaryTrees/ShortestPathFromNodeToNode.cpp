#include <bits/stdc++.h>
using namespace std;

bool found = false;

struct TreeNode{
    TreeNode *left, *right;
    int val;
    TreeNode(int x){
        val = x;
    }
};


void findRoute(TreeNode* root, int city, vector<string> &directions){
    /* complete the function to find route from root to city in terms of
    left right and up. Store it in directions */
    if(!root){
        directions.push_back("-1");
        return;
    }
    if(root->val == city){
        found = true;
        return;
    }
    else{
        if(root->left && !found){ 
            directions.push_back("left");
            findRoute(root->left, city, directions);
            if(!found)
                directions.pop_back();
        }
        if(root->right && !found){ 
            directions.push_back("right");
            findRoute(root->right, city, directions);
            if(!found)
                directions.pop_back();
        }
    }

}
vector<string> giveDirections(TreeNode* root, int A, int B){
    vector<string> rootToA;
    vector<string> rootToB;
    vector<string> res;
    findRoute(root, A, rootToA);
    found = false;
    findRoute(root, B, rootToB);
    /* complete the rest of the code */
    int sizea = rootToA.size();
    int sizeb = rootToB.size();
    int i= 0;
    while(i < sizea and i < sizeb){
        if(rootToA[i] != rootToB[i]) break;
        i++;
    }
    if(i < sizea and i < sizeb){
        int start = i;
        while(start < sizea){
            res.push_back("up");
            start++;
        }
        start = i;
        while(start < sizeb){
            res.push_back(rootToB[start]);
            start++;
        }
        return res;
    }
    else if(i < sizea){
        int start = i;
        while(start < sizea){
            res.push_back("up");
            start++;
        }
        return res;
    }
    else{
        int start = i;
        while(start < sizeb){
            res.push_back(rootToB[start]);
            start++;
        }
        return res;
    }
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

    vector<string> res = giveDirections(root, 8, 9);
    cout << "output begins" << endl;
    for(string i : res){
        cout << i <<" ";
    }
    cout << endl;
}