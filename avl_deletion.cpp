#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    int height;
    TreeNode(int x) {
        val = x;
        left = right = NULL;
        height = 1;
    }
};

// Height
int height(TreeNode *n) {
    if (!n) return 0;
    return n->height;
}

// Balance Factor
int balanceFactor(TreeNode *n) {
    if (!n) return 0;
    return height(n->left) - height(n->right);
}

// Right Rotation
TreeNode* rightRotation(TreeNode *root) {
    TreeNode *x = root->left;
    TreeNode *y = x->right;

    root->left = y;
    x->right = root;

    root->height = 1 + max(height(root->left), height(root->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

// Left Rotation
TreeNode* leftRotation(TreeNode *root) {
    TreeNode *x = root->right;
    TreeNode *y = x->left;

    root->right = y;
    x->left = root;

    root->height = 1 + max(height(root->left), height(root->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

// Find minimum node
TreeNode* minValueNode(TreeNode* root) {
    TreeNode* curr = root;
    while (curr->left)
        curr = curr->left;
    return curr;
}

// AVL Deletion
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return root;

    // BST Deletion
    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else {
        // One or no child
        if (!root->left || !root->right) {
            TreeNode* temp = root->left ? root->left : root->right;

            if (!temp) 
            {
                temp = root;
                root = NULL;
            } 
            else *root = *temp;

            delete temp;
        }
        else {
            // Two children
            TreeNode* temp = minValueNode(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
    }

    if (!root) return root;

    // Update height
    root->height = 1 + max(height(root->left), height(root->right));

    // Balance
    int bf = balanceFactor(root);

    // LL
    if (bf > 1 && balanceFactor(root->left) >= 0)
        return rightRotation(root);

    // LR
    if (bf > 1 && balanceFactor(root->left) < 0) {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    // RR
    if (bf < -1 && balanceFactor(root->right) <= 0)
        return leftRotation(root);

    // RL
    if (bf < -1 && balanceFactor(root->right) > 0) {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}
