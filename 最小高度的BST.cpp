#include <vector>
#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data):val(data),left(NULL),right(NULL){}
};

class MinimalBST {
public:
    int buildMinimalBST(vector<int> vals) {
        // write code here
        int len = vals.size();
        if(len <= 0)
            return 0;
        /**构建BST**/
        TreeNode* root = create(vals, 0, len-1);
        /**返回BST高度**/
        return hight(root);
    }

    TreeNode* create(vector<int> vals, int start, int end)
    {
        if(start > end)
            return nullptr;
        int mid = (start + end)/2;
        TreeNode* root = new TreeNode(vals[mid]);
        root->left = create(vals, start, mid-1);
        root->right = create(vals, mid+1, end);
        return root;
    }

    int hight(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        int left = hight(root->left);
        int right = hight(root->right);
        if(left > right)
            return left+1;
        else
            return right + 1;
    }
};
