#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Balance
{
public:
    bool isBalance(TreeNode* root)
    {
        if(check(root) == -1)
            return false;
        else
            return true;
    }

    int check(TreeNode* node)
    {
        if(node == nullptr)
            return 0;
        int left = check(node->left);
        if(left == -1)
            return -1;

        int right = check(node->right);
        if(right == -1)
            return -1;

        int dif = abs(left - right);
        if(dif > 1)
            return -1;
        else
            return max(left, right) + 1;
    }
};
