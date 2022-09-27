#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data)
    {
        this->data = data;
    }
    ~TreeNode()
    {
        for (int i = 0; i < root->children().size(); i++)
        {
            delete children[i];
        }
    }
};

template <typename T>
class MaxNodePair
{
public:
    TreeNode<T> *node;
    int sum;
};

template <typename T>
void printTree(TreeNode<T> *root)
{
    if (root == NULL)
        return;
    cout << root->data << " :children of roots are:" << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
        printTree(root->children[i]);
}

TreeNode<int> *takeInput()
{
    int data;
    cout << "enter data:" << endl;
    cin >> data;
    TreeNode<int> *root = new TreeNode<int>(data);
    int n;
    cout << "enter number of children: " << data << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTreeLevel(TreeNode<int> *root)
{
    queue<TreeNode<int> *> nodes;
    nodes.push(root);
    while (!nodes.empty())
    {
        TreeNode<int> *front = nodes.front();
        nodes.pop();
        cout << front->data << ": ";
        for (int i = 0; i < front->children.size(); i++)
        {
            if (i < (front->children.size() - 1))
                cout << front->children[i]->data << ",";
            else
                cout << front->children[i]->data;
            nodes.push(front->children[i]);
        }
        cout << "\n";
    }
    return;
}

TreeNode<int> *takeInputLavel()
{
    int data;
    cout << "Enter root data:" << endl;
    cin >> data;
    TreeNode<int> *root = new TreeNode<int>(data);
    queue<TreeNode<int> *> Nodes;
    Nodes.push(root);
    while (Nodes.size() != 0)
    {
        TreeNode<int> *front = Nodes.front();
        Nodes.pop();
        cout << "Enter number of children of :" << front->data << endl;
        int num;
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            int ch;
            cout << "Enter " << i << " th child of: " << front->data << endl;
            cin >> ch;
            TreeNode<int> *child = new TreeNode<int>(ch);
            front->children.push_back(child);
            Nodes.push(child);
        }
    }
    return root;
}

int NumberofRoot(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += NumberofRoot(root->children[i]);
    }
    return ans;
}

int SumofRoot(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int ans = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += SumofRoot(root->children[i]);
    }
    return ans;
}

TreeNode<int> *maxDataNode(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return root;
    }

    TreeNode<int> *max = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *maxChild = maxDataNode(root->children[i]);
        if (maxChild->data > max->data)
        {
            max = maxChild;
        }
    }
    return max;
}

int getHeight(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = 0;

    for (int i = 0; i < root->children.size(); i++)
    {
        int childHeight = getHeight(root->children[i]);
        if (childHeight > ans)
        {
            ans = childHeight;
        }
    }

    return ans + 1;
}

void printLevelK(TreeNode<int> *root, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printLevelK(root->children[i], k - 1);
    }
}

int getLeafNodeCount(TreeNode<int> *root)
{
    int count = 0;

    if (root->children.size() == 0)
    {
        count++;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        count += getLeafNodeCount(root->children[i]);
    }
    return count;
}

void pre_order(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << ",";
    for (int i = 0; i < root->children.size(); i++)
    {
        pre_order(root->children[i]);
    }
}

void post_order(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    for (int i = 0; i < root->children.size(); i++)
    {
        post_order(root->children[i]);
    }

    cout << root->data << ",";
}

bool findx(TreeNode<int> *root, int x)
{

    if (root->data == x)
        return true;
    for (int i = 0; i < root->children.size(); i++)
    {
        bool ans = findx(root->children[i], x);
        if (ans)
            return true;
    }
    return false;
}

TreeNode<int> *maxSumNode1(TreeNode<int> *root)
{

    TreeNode<int> *ans = root;

    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++) ///  sum for root node
    {
        sum += root->children[i]->data;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *childmax = maxSumNode1(root->children[i]); // get the max node using recursion

        int smallsum = childmax->data;

        for (int i = 0; i < childmax->children.size(); i++) // calculating sum for max node
        {
            smallsum += childmax->children[i]->data;
        }

        if (sum <= smallsum) // comparision  update if necessary
        {
            ans = childmax;
            sum = smallsum;
        }
    }
    return ans;
}

MaxNodePair<int> *maxSumNodeHelper(TreeNode<int> *root)
{
    if (root == NULL)
    {
        MaxNodePair<int> *pair = new MaxNodePair<int>();
        pair->node = NULL;
        pair->sum = INT_MIN;
        return pair;
    }

    int sum = root->data;

    for (int i = 0; i < root->children.size(); i++)
    {
        sum += root->children[i]->data;
    }

    MaxNodePair<int> *ans = new MaxNodePair<int>();
    ans->node = root;
    ans->sum = sum;

    for (int i = 0; i < root->children.size(); i++)
    {
        MaxNodePair<int> *childAns = maxSumNodeHelper(root->children[i]);
        if (childAns->sum > ans->sum)
        {
            ans = childAns;
        }
    }

    return ans;
}

bool areIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }

    if ((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL))
    {
        return false;
    }

    if ((root1->data != root2->data) || (root1->children.size() != root2->children.size()))
    {
        return false;
    }

    for (int i = 0; i < root1->children.size(); ++i)
    {
        bool ans = areIdentical(root1->children[i], root2->children[i]);
        if (ans)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    /*TreeNode<int> *root = new TreeNode<int>(1);
    TreeNode<int> *node1 = new TreeNode<int>(5);
    TreeNode<int> *node2 = new TreeNode<int>(6);
    root->children.push_back(node1);
    root->children.push_back(node2);*/
    TreeNode<int> *root = takeInputLavel();
    printTreeLevel(root);
    cout << endl;
    // cout << " total number of roots are: " << NumberofRoot(root);
    // cout << " total sum is: " << SumofRoot(root);
    // cout << " maximum is: " << maxDataNode(root)->data;
    // cout << " height is: " << getHeight(root);
    // cout << "level roots are: " << endl;
    // printLevelK(root, 2);
    // pre_order(root);
    // cout << endl;
    // post_order(root);
    // cout << findx(root, 5);
    // cout << "maximum is: " << maxSumNode(root)->data;
    delete root;
}
