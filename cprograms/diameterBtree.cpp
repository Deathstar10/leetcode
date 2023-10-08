#include <queue>
#include <algorithm>
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

int findRightHeight(TreeNode *root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 0;
    TreeNode *temp = root;
    int height = 0;
    while (!temp == NULL)
    {
        height++;
        if (temp->right == NULL)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    return height - 1;
}

int findLeftHeight(TreeNode *root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 0;
    TreeNode *temp = root;
    int height = 0;
    while (!temp == NULL)
    {
        height++;
        if (temp->left == NULL)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }

    return height - 1;
}
int maximum = 0;

int diameterOfBinaryTree(TreeNode *root)
{
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

int height(TreeNode *root, int &diameter)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);

    diameter = max(diameter, lh + rh);

    return 1 + max(lh, rh);
}