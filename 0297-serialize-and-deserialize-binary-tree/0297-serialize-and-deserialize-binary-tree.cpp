/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string code;
    int ind=0;
    Codec(){
        code="";
    }
    // Encodes a tree to a single string.
    void mySerialize(TreeNode* root) {
        if(!root){
            code+="#";
            return;
        }
        int val=root->val;
        code+=to_string(val);
        code+=",";
        mySerialize(root->left);
        mySerialize(root->right);
        return;
    }
    string serialize(TreeNode* root) {
        mySerialize(root);
        cout<<code<<endl;
        return code;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data[ind] == '#') {
            ind++;
            return NULL;
        }
        
        string num = "";
        int n;
        
        if(data[ind] == '-') {
            ind++;
            while(data[ind] != ',') {
                num.push_back(data[ind]);
                ind++;
            }
            n = -stoi(num);
            ind++;
        } else {
            while(data[ind] != ',') {
                num.push_back(data[ind]);
                ind++;
            }
            n = stoi(num);
            ind++;
        }
        
        TreeNode* node = new TreeNode(n);
        node->left = deserialize(data);
        node->right = deserialize(data);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));