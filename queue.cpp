#include <bits/stdc++.h>
using namespace std;
class arrqueue
{

    int *data;
    int firstIndex;
    int nextIndex;
    int size;
    int capacity;

public:
    arrqueue(int s)
    {
        data = new int[s];
        capacity = s;
        size = 0;
        firstIndex = -1;
        nextIndex = 0;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void enqueue(int element)
    {
        if (size == capacity)
        {
            int *newData = new int[2 * capacity];
            int k = 0;
            for (int i = firstIndex; i < capacity; i++)
            {
                /* code */
                newData[k] = data[i];
                k++;
            }
            for (int i = 0; i < firstIndex; i++)
            {
                /* code */
                newData[k] = data[i];
                k++;
            }
            delete[] data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        if (firstIndex == -1)
            firstIndex = 0;
        size++;
    }
    int front()
    {
        if (isEmpty())
        {
            cout << "empty queue" << endl;
        }
        return data[firstIndex];
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "queue empty" << endl;
            return 0;
        }
        int ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        if (size == 0)
        {
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }
};

int main()
{
    arrqueue q1(5);

    q1.enqueue(15);
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(300);
    q1.enqueue(40);
    cout << q1.getSize() << endl;
    cout << q1.front() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.front() << endl;
}
