#include <algorithm>
#include <iostream>
#include <map>
#include <queue>

#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> bottomView(TreeNode *root)
{
    if (root == NULL)
    {
        return {};
    }
    map<int, int> orderMap;
    queue<pair<TreeNode *, int>> traversalQueue;
    vector<int> result;

    traversalQueue.push({root, 0});

    while (!traversalQueue.empty())
    {
        pair<TreeNode *, int> temp = traversalQueue.front();
        orderMap[temp.second] = temp.first->val;

        if (temp.first->left != NULL)
        {
            traversalQueue.push({temp.first->left, temp.second - 1});
        }

        if (temp.first->right != NULL)
        {
            traversalQueue.push({temp.first->right, temp.second + 1});
        }

        traversalQueue.pop();
    }

    for (const auto &pair : orderMap)
    {
        result.push_back(pair.second);
    }

    return result;
}

int main()
{
    // Creating nodes for the binary tree
    TreeNode *root = new TreeNode(1);
    TreeNode *leftChild = new TreeNode(2);
    TreeNode *rightChild = new TreeNode(3);
    TreeNode *leftGrandchild = new TreeNode(4);
    TreeNode *rightGrandchild = new TreeNode(5);

    // Building the binary tree structure
    root->left = leftChild;
    root->right = rightChild;
    leftChild->left = leftGrandchild;
    leftChild->right = rightGrandchild;
    vector<int> myvector = {-2, -1};

    vector<int> max = bottomView(root);

    for (const int vec : max)
    {
        cout << vec << " ";
    }

    delete root;
    delete leftChild;
    delete rightChild;
    delete leftGrandchild;
    delete rightGrandchild;

    return 0;
}
