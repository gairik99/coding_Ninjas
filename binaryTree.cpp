#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

BinaryTreeNode<int> *takeInputLevel()
{
    int data;
    cout << "enter root data: ";
    cin >> data;
    if (data == -1)
        return NULL;
    queue<BinaryTreeNode<int> *> node;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);
    node.push(root);
    while (node.size() != 0)
    {
        BinaryTreeNode<int> *front = node.front();
        node.pop();

        cout << "enter left child of " << front->data << ":";
        int leftchild;
        cin >> leftchild;
        if (leftchild != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftchild);
            front->left = child;
            node.push(child);
        }

        cout << "enter right child of " << front->data << ":";
        int rightchild;
        cin >> rightchild;
        if (rightchild != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightchild);
            front->right = child;
            node.push(child);
        }
    }
    return root;
}

BinaryTreeNode<int> *takeInput()
{
    int data;
    cout << "enter root data: ";
    cin >> data;
    if (data == -1)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);
    BinaryTreeNode<int> *leftchild = takeInput();
    BinaryTreeNode<int> *rightchild = takeInput();
    root->left = leftchild;
    root->right = rightchild;
    return root;
}

void printBinaryTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << ":";
    if (root->left != NULL)
        cout << "L" << root->left->data;
    if (root->right != NULL)
        cout << "R" << root->right->data;
    cout << endl;
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}

void printBinaryTreeLevel(BinaryTreeNode<int> *node)
{
    queue<BinaryTreeNode<int> *> node;
    node.push(root);
    while (node.size() != 0)
    {
        BinaryTreeNode<int> *front = node.front();
        node.pop();
        cout << front->data << ":";
        if (front->left != NULL)
        {
            node.push(front->left);
            cout << "L:" << front->left->data << ",";
        }
        else
            cout << "L:" << -1 << ",";

        if (front->right != NULL)
        {
            node.push(front->right);
            cout << "R:" << front->right->data << endl;
        }
        else
            cout << "R:" << -1 << endl;
    }
}

int main()
{
    /*BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);
    root->left = node1;
    root->right = node2;*/
    // BinaryTreeNode<int> *root = takeInput();
    BinaryTreeNode<int> *root = takeInputLevel();
    printBinaryTree(root);
}