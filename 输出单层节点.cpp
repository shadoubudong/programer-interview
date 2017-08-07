#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class TreeLevel {
public:
    ListNode* getTreeLevel(TreeNode* root, int dep) {
        // write code here
        if(root == nullptr)
            return nullptr;
        ListNode* pRoot = new ListNode(-1);//虚结点
        ListNode* pNode = pRoot;
        queue<TreeNode*> nodequeue;
        nodequeue.push(root);
        vector<int> vec;//存储dep层的数据
        int layer = 1;
        while(!nodequeue.empty())
        {
            int i = 0;
            int len = nodequeue.size();
            vector<int> tmp;
            for(i=0; i<len; i++)
            {
                TreeNode* node = nodequeue.front();
                nodequeue.pop();
                tmp.push_back(node->val);
                if(node->left)
                    nodequeue.push(node->left);
                if(node->right)
                    nodequeue.push(node->right);
            }
            if(layer == dep)
            {
                vec = tmp;
                break;
            }
            layer++;
        }
        /**将dep层的数据构建出一个链表返回**/
        for(int i=0; i<vec.size();i++)
        {
            ListNode* tmp = new ListNode(vec[i]);
            pNode->next = tmp;
            pNode = pNode->next;
        }
        return pRoot->next;
    }
};
