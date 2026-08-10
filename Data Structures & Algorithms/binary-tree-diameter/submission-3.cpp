/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:


   int diameter(TreeNode* root){

    if(root==NULL){
        return 0;
    }


    int d=0;



    int left = 1+diameter(root->left);
    int right = 1+ diameter(root->right);

    d = max(d, (left+right)/2);


    return d;

}

    int diameterOfBinaryTree(TreeNode* root) {



        return diameter(root);



     
    }
};
