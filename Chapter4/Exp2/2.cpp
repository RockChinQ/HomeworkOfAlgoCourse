
#include <iostream> 
using namespace std; 
 
struct TreeNode 
{ 
    int val; 
    TreeNode *left; 
    TreeNode *right; 
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} 
}; 
 
TreeNode* insert(TreeNode* root, int val) 
{ 
    if (root == NULL) 
        return new TreeNode(val); 
    if (val < root->val) 
        root->left  = insert(root->left, val); 
    else if (val > root->val) 
        root->right = insert(root->right, val); 
    return root; 
} 
 
void preorder(TreeNode *root) 
{ 
    if (root == NULL) 
        return; 
    cout << root->val << " "; 
    preorder(root->left); 
    preorder(root->right); 
} 
 
int main() 
{ 
    int val; 
    TreeNode *root = NULL; 
    // cout << "请输入一系列整数（以空格分开），以-1作为结束标志（-1不作为数据输入）:"; 
    while (cin >> val && val != -1) 
        root = insert(root, val); 
    // cout << "前序遍历的结果为:"; 
    preorder(root); 
    cout << endl; 
    return 0; 
}