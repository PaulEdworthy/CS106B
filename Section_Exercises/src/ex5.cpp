#include <iostream>
#include <stack>
#include <queue>

void collectionMystery(std::stack<int> &s);

int main()
{
    std::stack<int> s;
    std::stack<int> t;
    std::stack<int> p;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    t.push(42);
    t.push(3);
    t.push(12);
    t.push(15);
    t.push(9);
    t.push(71);
    t.push(88);

    p.push(65);
    p.push(30);
    p.push(10);
    p.push(20);
    p.push(45);
    p.push(55);
    p.push(6);
    p.push(1);
    
    collectionMystery(s);
}

#include <iostream>
#include <stack>
#include <queue>

void collectionMystery(std::stack<int>& s) {
    std::queue<int> q;
    std::stack<int> s2;

    // Process the original stack
    while (!s.empty()) {
        if (s.top() % 2 == 0) {
            q.push(s.top()); // Push even numbers to the queue
            s.pop();
        } else {
            s2.push(s.top()); // Push odd numbers to the auxiliary stack
            s.pop();
        }
    }

    // Move elements from the queue back to the original stack
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    // Move elements from the auxiliary stack back to the original stack
    while (!s2.empty()) {
        s.push(s2.top());
        s2.pop();
    }

    // Print the stack (top to bottom)
    std::stack<int> temp = s; // Use a temporary stack to preserve the original
    std::cout << "Stack contents (top to bottom): ";
    while (!temp.empty()) {
        std::cout << temp.top() << " ";
        temp.pop();
    }
    for (int i = 0; i < s.size(); i++) {
        
    }
}
