/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node* solve(Node* node, unordered_map<Node*,Node*> &copy) {
        Node* clone = new Node(node->val);
        copy[node] = clone;
        
        for(auto nbr:node->neighbors) {
            if(copy.find(nbr) == copy.end()) {
                clone->neighbors.push_back(solve(nbr,copy));
            } else {
                clone->neighbors.push_back(copy[nbr]);
            }
        }
        
        return clone;
    }
    
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*,Node*> copy;
        return solve(node,copy);
        
    }
};