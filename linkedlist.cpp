#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class pair1
{
public:
    node *head;
    node *tail;
};

node *insertnode(node *head, int i, int data)
{
    node *n1 = new node(data);
    int cnt = 0;
    node *temp = head;
    if (i == 0)
    {
        n1->next = head;
        head = n1;
        return head;
    }
    while (temp != NULL && cnt < i - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp != NULL)
    {
        n1->next = temp->next;
        temp->next = n1;
    }
    return head;
}

node *createlink()
{
    int data;
    cin >> data;
    node *head = NULL;
    node *tail = NULL;
    while (data != -1)
    {
        node *n1 = new node(data);
        if (head == NULL)
        {
            head = n1;
            tail = n1;
        }
        /*else{
            node* temp=head;
            while(temp->next!=NULL)
                temp=temp->next;

            temp->next=n1;
        }*/
        else
        {
            tail->next = n1;
            tail = tail->next;
        }

        cin >> data;
    }
    return head;
}
node *reverselink(node *head)
{
    node *newnode = NULL;
    while (head != NULL)
    {
        node *next = head->next;
        head->next = newnode;
        newnode = head;
        head = next;
    }
    return newnode;
}

pair1 reversell(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        pair1 ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    pair1 head1 = reversell(head->next);
    head1.tail->next = head;
    head->next = NULL;
    pair1 ans;
    ans.head = head1.head;
    ans.tail = head;
    return ans;
}
node *reversell_2(node *head)
{
    return reversell(head).head;
}
node *reverse23(node *head)
{
    node *current = head, *next = NULL, *prev = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

bool palinlinkedlist(node *head)
{
    if (head == NULL || head->next == NULL)
        return true;
    node *slow = head;
    node *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverselink(slow->next);
    slow = slow->next;
    while (slow != NULL)
    {
        if (slow->data != head->data)
            return false;
        slow = slow->next;
        head = head->next;
    }
    return true;
}

node *middle(node *head)
{
    if (head == NULL)
        return head;
    node *slow = head;
    // node *h2 = head;
    node *fast = head;
    // int cnt = 0;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
node *mergeTwoSortedLinkedLists(node *head1, node *head2)
{
    // Write your code here
    if (head1 == NULL && head2 == NULL)
        return head1;
    if (head1 == NULL || head2 == NULL)
    {
        if (head1 == NULL)
            return head2;
        else
            return head1;
    }

    node *th = NULL;
    node *tail = NULL;
    if (head1->data < head2->data)
    {
        th = head1;
        tail = head1;
        head1 = head1->next;
    }
    else
    {
        th = head2;
        tail = head2;
        head2 = head2->next;
    }

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            tail->next = head1;
            tail = tail->next;
            head1 = head1->next;
        }
        else
        {
            tail->next = head2;
            tail = tail->next;
            head2 = head2->next;
        }
    }
    while (head1 != NULL)
    {
        tail->next = head1;
        tail = tail->next;
        head1 = head1->next;
    }
    while (head2 != NULL)
    {
        tail->next = head2;
        tail = tail->next;
        head2 = head2->next;
    }
    return th;
}
node *mergeSort(node *head)
{
    // Write your code here
    if (head == NULL || head->next == NULL)
        return head;

    node *h1 = middle(head);
    node *temp = h1->next;
    h1->next = NULL;
    node *head1 = mergeSort(head);
    node *head2 = mergeSort(temp);
    head1 = mergeTwoSortedLinkedLists(head1, head2);
    return head1;
}

void print1(node *head)
{
    node *temp = head;
    do
    {
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    } while (temp != NULL);
    cout << endl;
}
int main()
{
    /*node n1(1);
    node* head=&n1;
    node n2(2);
    n1.next=&n2;
    node n3(3);
    n2.next=&n3;
    node n4(4);
    n3.next=&n4;*/
    /*
    node* n1=new node(1);
    node* head=n1;
    node* n2=new node(2);
    n1->next=n2;
    node* n3=new node(3);
    n2->next=n3;
    node* n4=new node(4);
    n3->next=n4;

    */
    node *head = createlink();
    print1(head);
    cout << endl;
    // head=insertnode(head,3,89);
    // head=reverselink(head);
    // print1(head);
    // node* ba=middle(head);
    // cout<<ba->data;
    // bool h1 = palinlinkedlist(head);
    /* if (h1)
         cout << "true" << endl;
     else
         cout << "false" << endl;
    */
    // node *head1 = mergeSort(head);
    // node *head1 = reversell_2(head);
    // print1(head1);
    node *head1 = reverse23(head);
    print1(head1);
}