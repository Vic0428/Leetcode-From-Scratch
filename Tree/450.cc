/**
 * Leetcode 450:  Delete Node in a BST
 * Author: Weiqi Feng
 * Email: fengweiqi@sjtu.edu.cn
 * Date:  November 4, 2019
 * Copyright 2019 Vic
 */ 
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
	// Not found key!
        if (root == nullptr) {
            return nullptr;
        } else if (key < root->val) {
	    // Update left subtree		
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
	    // Update right subtree
            root->right = deleteNode(root->right, key);
        } else {
	    // Case 1: with no children	
            if (root->left == nullptr && root->right == nullptr) {
                return nullptr;
            // Case 2: with only right children
            } else if (root->left == nullptr) {
                return root->right;
	    // Case 3: with only left children	
            } else if (root->right == nullptr) {
                return root->left;
	    // Case 4: with both children	
            } else {
		// Use target node's successor to replace target node    
                TreeNode* sucessor = findMin(root->right);
                root->val = sucessor->val;
                root->right = deleteNode(root->right, root->val);
            }
        }
        return root;
    }

    /** Find min value under root
      * Parameter: root - root node
      */ 
    TreeNode* findMin(TreeNode* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }
};
