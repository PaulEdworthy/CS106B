#include <iostream>
#include <stack>

void splitStack(std::stack<int>& s);

int main()
{
    std::stack<int> s;
    s.push(4);
    s.push(0);
    s.push(-1);
    s.push(5);
    s.push(-6);
    s.push(-3);
    s.push(2);
    s.push(7);

    splitStack(s);
}

// TODO
// Unfinished. Stanford solution uses a queue to store \
the numbers and enqueue and dequeue items
// I'm trying to do it in place in the same structure
void splitStack(std::stack<int>& s)
{
    std::stack<int> temp;
    while (!s.empty())
    {
        if (s.top() >= 0)
        {
            temp.push(s.top());
        }
        s.pop();
    }
    while (!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
    std::stack<int> printStack = s;
    while (!printStack.empty())
    {
        std::cout << printStack.top() << " ";
        printStack.pop();
    }
    std::cout << "\n";
}
