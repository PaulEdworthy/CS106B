#include <iostream>
#include <deque>
#include <queue>

// void duplicateElementsD(std::deque<int>& q);
void duplicateElements(std::queue<int>& q);

int main() {
    std::deque<int> q = {1, 2, 3, 4, 5};
    std::queue<int> p;
    p.push(1);
    p.push(2);
    p.push(3);
    p.push(4);
    p.push(5);

    // duplicateElementsD(q);
    duplicateElements(p);
}

// Using a deque
void duplicateElementsD(std::deque<int>& q) {
   for(int i = 0; i < q.size(); i++) {
       q.insert(q.begin() + i, q[i]);
       i++; // Advance 1 more position to account for the new item
   }

   for(int i = 0; i < q.size(); i++) {
       std::cout << q[i] << " ";
   }
}

// Using a queue
void duplicateElements(std::queue<int>& p) {
    int size = p.size();
    for(int i = 0; i < size; i++){
        int n = p.front();
        p.pop();
        p.push(n);
        p.push(n);
    }
    for (int i = 0; i < p.size(); i++) {
        std::cout << p.front() << " ";
        p.pop();
        p.push(p.front());
    }
}