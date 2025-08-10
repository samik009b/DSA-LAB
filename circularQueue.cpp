#include <iostream>
using namespace std;
#define SIZE 3

class queue
{
    int q[SIZE], start = -1, end = -1;

public:
    void push()
    {
        int x;
        if ((start == 0 && end == SIZE - 1) || ((end + 1) % SIZE == start))
        {
            cout << "queue is full\n";
            return;
        }
        else if (start == -1)
        {
            start = 0;
            end = 0;
        }
        else
        {
            end = (end + 1) % SIZE;
        }
        cout << "enter the value : ";
        cin >> x;
        q[end] = x;
    }

    void pop()
    {
        if (start == -1)
        {
            cout << "1queue empty\n";
            return;
        }
        else if (start == end)
        {
            start = end = -1;
        }
        else
        {
            start = (start + 1) % SIZE;
        }
        cout << "item deleted\n";
    }

    void display()
    {
        if (start == -1)
        {
            cout << "queue empty\n";
            return;
        }
        else
        {
            int i = start;
            while (true)
            {
                cout << q[i];
                if (i == end)
                {
                    break;
                }
                i = (i + 1) % SIZE;
            }
        }
    }
};
int main()
{
    queue q;
    int choice;

    while (1)
    {
        cout << "\nenter choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            q.push();
            break;

        case 2:
            q.pop();
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << "\nterminated";
            return 0;

        default:
            break;
        }
    }

    return 0;
}