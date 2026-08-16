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

// class Codec {
// public:



//    void serializePreOrder(Node* root, vector<int> &arr) {
    
//     // Push -1 if root is null.
//     if (root == nullptr) {
//         arr.push_back(-1);
//         return;
//     }
    
//     // Push the root into result.
//     arr.push_back(root->data);
//     serializePreOrder(root->left, arr);
//     serializePreOrder(root->right, arr);
// }


//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//          vector<int> arr;
//     serializePreOrder(root, arr);
//     return arr;
        
//     }



//     Node* deserializePreOrder(int &i, vector<int> &arr) {
    
//     // if element is -1 return null
//     if (arr[i] == -1){
//         i++;
//         return nullptr;
//     }
    
//     // Create the root node.
//     Node* root = new Node(arr[i]);
//     i++;
    
//     // Create the left and right subtree.
//     root->left = deserializePreOrder(i, arr);
//     root->right = deserializePreOrder(i, arr);
    
//     return root;
// }


//     TreeNode* deserialize(string data) {
//          int i = 0;
//    return deserializePreOrder(i, arr);
        
//     }
// };
class Codec {
public:

    void serializePreOrder(TreeNode* root, vector<int>& arr) {

        if (root == nullptr) {
            arr.push_back(-1);
            return;
        }

        arr.push_back(root->val);

        serializePreOrder(root->left, arr);
        serializePreOrder(root->right, arr);
    }


    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        vector<int> arr;

        serializePreOrder(root, arr);

        string data = "";

        for (int x : arr) {
            data += to_string(x) + ",";
        }

        return data;
    }


    TreeNode* deserializePreOrder(int& i, vector<int>& arr) {

        if (arr[i] == -1) {
            i++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(arr[i]);
        i++;

        root->left = deserializePreOrder(i, arr);
        root->right = deserializePreOrder(i, arr);

        return root;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        vector<int> arr;

        string temp = "";

        for (char c : data) {

            if (c == ',') {
                arr.push_back(stoi(temp));
                temp = "";
            }
            else {
                temp += c;
            }
        }

        int i = 0;

        return deserializePreOrder(i, arr);
    }
};