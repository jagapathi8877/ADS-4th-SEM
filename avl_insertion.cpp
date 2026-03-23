#include<bits/stdc++.h>
using namespace std ;

class TreeNode
{
public :
    int val;
    TreeNode *left  ;
    TreeNode *right ;
    int height ;
    TreeNode(int x)
    {
        val = x ;
        left = right = NULL ;
        height = 1 ;
    }
};

int height(TreeNode *n)
{
    if(!n) return 0 ;
    return n->height ;
}

int balanceFactor(TreeNode *n)
{
    if(!n) return 0 ;
    return height(n->left) - height(n->right);
}

TreeNode *rightRotation(TreeNode *root)
{
    TreeNode *x = root->left ;
    TreeNode *y = x->right ;

    root->left = y ;
    x->right = root ;

    root->height = 1 + max(height(root->left) , height(root->right));
    x->height = 1 + max(height(x->left) , height(x->right)) ;
    return x ;
}
TreeNode *leftRotation(TreeNode *root)
{
    TreeNode *x = root->right ;
    TreeNode *y = x->left ;

    root->right = y ;
    x->left = root ;

    root->height = 1 + max(height(root->left) , height(root->right));
    x->height = 1 + max(height(x->left) , height(x->right)) ;
    return x ;
}

TreeNode *insert(TreeNode *root , int val)
{
    if(!root) return new TreeNode(val);
    else if(val < root->val) root->left = insert(root->left ,val) ;
    else if(val > root->val) root->right = insert(root->right , val) ;

    root->height = 1 + max(height(root->left) , height(root->right)) ;
    int bf = balanceFactor(root);
    //LL
    if(bf > 1 && val < root->left->val) return rightRotation(root) ;
    //LR
    if(bf > 1 && val > root->left->val) 
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    //RR
    if(bf < -1 && val > root->right->val) return leftRotation(root);
    //RL
    if(bf < -1 && val < root->right->val) 
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
    return root ;
}

void pre(TreeNode *root)
{
    if(!root) return ;
    cout << root->val << " " ;
    pre(root->left);
    pre(root->right);
}

int main()
{
    TreeNode *root = NULL ;
    vector<int>arr = {10,20,30,40,50,25} ;
    for(int i : arr) root = insert(root , i) ;
    pre(root) ;
}
