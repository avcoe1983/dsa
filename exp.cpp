//practical 6(DSA)
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
    char data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(char val) : data(val), left(nullptr), right(nullptr) {}
};

bool isOperand(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

TreeNode *constructExpressionTree(const string &prefix)
{
    stack<TreeNode *> stk;

    for (int i = prefix.length() - 1; i >= 0; --i)
    {
        char c = prefix[i];

        if (isOperand(c))
        {
            stk.push(new TreeNode(c));
        }
        else
        {
            TreeNode *newNode = new TreeNode(c);
            newNode->left = stk.top();
            stk.pop();
            newNode->right = stk.top();
            stk.pop();

            stk.push(newNode);
        }
    }

    return stk.top();
}

void postOrderTraversalAndDelete(TreeNode *root)
{
    stack<TreeNode *> stk;
    TreeNode *current = root;
    TreeNode *lastVisited = nullptr;

    while (current || !stk.empty())
    {
        if (current)
        {
            stk.push(current);
            current = current->left;
        }
        else
        {
            TreeNode *topNode = stk.top();

            if (topNode->right && lastVisited != topNode->right)
            {
                current = topNode->right;
            }
            else
            {
                cout << topNode->data << " ";

                lastVisited = topNode;
                stk.pop();
                delete topNode;
                
            }
        }
    }
}

int main()
{
    cout<<"Prepared By - Anshul Singh"<<endl;
    cout<<"DSAL Practical 05 (B-7)"<<endl;
    string prefixExpression ;
    cout<<"Enter the Prefix Expression"<<endl;
    cin>>prefixExpression;
    
    TreeNode *root = constructExpressionTree(prefixExpression);

    postOrderTraversalAndDelete(root); 

    return 0;
}