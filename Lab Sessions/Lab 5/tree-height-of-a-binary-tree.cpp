#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }


        /*The tree node has data, left child and right child
        class Node {
            int data;
            Node* left;
            Node* right;
        };

        */
      int height(Node* root) {

          // If the root of a binary tree in NULL. There's nothing to take the height. No tree condition.
          if(root == NULL) return -1;

          // The Height of binary tree with single node is taken as zero.(defined in the problem above)
          else if (root->left == NULL && root->right == NULL) return 0;

          // If a given node has children, the function will be called recursively.
          else{
              int left_height = height(root->left);
              int right_height = height(root->right);
              return max(left_height, right_height) +1; // since height is the longest root-to-leaf path.
          }
      }
}; //End of Solution

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    int height = myTree.height(root);
    std::cout << height;

    return 0;
}
