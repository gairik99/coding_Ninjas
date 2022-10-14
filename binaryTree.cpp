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

class BalancedReturnType
{
public:
    int height;
    bool balanced;
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

void printBinaryTreeLevel(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
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

void printLevelWise(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *frontNode = pendingNodes.front();
        pendingNodes.pop();
        if (frontNode == NULL)
        {
            cout << "\n";
            if (!pendingNodes.empty())
            {
                pendingNodes.push(NULL);
            }
        }
        else
        {
            cout << frontNode->data << " ";
            if (frontNode->left != NULL)
            {
                pendingNodes.push(frontNode->left);
            }
            if (frontNode->right != NULL)
            {
                pendingNodes.push(frontNode->right);
            }
        }
    }
}

int countNodes(BinaryTreeNode<int> *root)
{
    int ans1 = 0, ans2 = 0;
    if (root == NULL)
        return 0;
    ans1 += countNodes(root->left);
    ans2 += countNodes(root->right);
    return (1 + ans1 + ans2);
}

bool isNodePresent(BinaryTreeNode<int> *root, int x)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == x)
    {
        return true;
    }
    return isNodePresent(root->left, x) || isNodePresent(root->right, x);
}

int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int ans1 = 1, ans2 = 1;
    ans1 += height(root->left);
    ans2 += height(root->right);
    return max(ans1, ans2);
}

void mirrorBinaryTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);

    BinaryTreeNode<int> *templeft = root->left;
    root->left = root->right;
    root->right = templeft;
}

void inOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << ",";
    inOrder(root->right);
}

void preOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

BinaryTreeNode<int> *buildFromPre(int in[], int pre[], int inS, int inE, int preS, int preE)
{
    if (inS > inE)
        return NULL;
    int rootData = pre[preS];
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    int linS = inS;
    int linE = rootIndex - 1;
    int lpreS = preS + 1;
    int lpreE = linE - linS + lpreS;
    int rpreS = lpreE + 1;
    int rpreE = preE;
    int rinS = rootIndex + 1;
    int rinE = inE;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = buildFromPre(in, pre, linS, linE, lpreS, lpreE);
    root->right = buildFromPre(in, pre, rinS, rinE, rpreS, rpreE);
    return root;
}

BinaryTreeNode<int> *buildFromPost(int in[], int post[], int inS, int inE, int postS, int postE)
{
    if (inS > inE)
        return NULL;
    int rootData = post[postE];
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    int linS = inS;
    int linE = rootIndex - 1;
    int lpostS = postS;
    int lpostE = linE - linS + lpostS;
    int rpostS = lpostE + 1;
    int rpostE = postE - 1;
    int rinS = rootIndex + 1;
    int rinE = inE;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = buildFromPost(in, post, linS, linE, lpostS, lpostE);
    root->right = buildFromPost(in, post, rinS, rinE, rpostS, rpostE);
    return root;
}

int getSum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftSum = getSum(root->left);
    int rightSum = getSum(root->right);
    return leftSum + rightSum + root->data;
}

BalancedReturnType *isBalancedHelper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        BalancedReturnType *ans = new BalancedReturnType();
        ans->height = 0;
        ans->balanced = true;
        return ans;
    }
    BalancedReturnType *ans1 = isBalancedHelper(root->left);
    BalancedReturnType *ans2 = isBalancedHelper(root->right);
    bool flag;
    if (!(ans1->balanced) || !(ans2->balanced) ||
        abs(ans1->height - ans2->height) > 1)
    {
        flag = false;
    }
    else
    {
        flag = true;
    }
    BalancedReturnType *output = new BalancedReturnType();
    output->height = max(ans1->height, ans2->height) + 1;
    output->balanced = flag;
    return output;
}

bool isBalanced(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }

    return isBalancedHelper(root)->balanced;
}

int main()
{
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1

    /*BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);
    root->left = node1;
    root->right = node2;
    */
    // BinaryTreeNode<int> *root = takeInput();
    BinaryTreeNode<int> *root = takeInputLevel();
    // int in[] = {4, 2, 5, 1, 8, 6, 9, 3, 7};
    // int post[] = {4, 5, 2, 8, 9, 6, 7, 3, 1};
    BinaryTreeNode<int> *root = buildFromPost(in, post, 0, 8, 0, 8);
    // int pre[] = {1, 2, 4, 5, 3, 6, 8, 9, 7};
    // BinaryTreeNode<int> *root = buildFromPre(in, pre, 0, 8, 0, 8);
    cout << endl;
    // printBinaryTree(root);
    // printBinaryTreeLevel(root);
    printLevelWise(root);
    // cout << countNodes(root);
    // cout << isNodePresent(root, 8);
    // cout << height(root);
    // cout << endl;
    // inOrder(root);
    delete root;
}