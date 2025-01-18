// my project

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "console.h"
#include "filelib.h"
#include "grid.h"
#include "gwindow.h"
#include "simpio.h"
#include "strlib.h"
#include "stack.h"
#include "queue.h"
using namespace std;

void mirrorTest();
void mirror(Grid<int> &grid);
void plusSumTest();
int plusSum(Grid<int> &grid, int row, int col);
void stretchTest();
void stretch(Vector<int> &v);
void consecutiveDuplicatesTest();
void removeConsecutiveDuplicates(Vector<int> &v);
void mysteryTest();
void collectionMystery(Stack<int>& s);
void duplicateElementsTest();
void duplicateElements(Queue<int> &q);
void splitStackTest();
void splitStack(Stack<int> &stack);
void keithNumbersTest();
bool findKeithSequence(Vector<int> &sequence, int n);
void findKeithNumbers(int min, int max);
void averageInFileTest();
double averageValueInFile(string filename);
void nameDiamondTest();
void nameDiamond(string s);

int main() {
    mirrorTest();
    plusSumTest();
    stretchTest();
    consecutiveDuplicatesTest();
    mysteryTest();
    duplicateElementsTest();
    splitStackTest();
    keithNumbersTest();
    averageInFileTest();
    nameDiamondTest();
    return 0;
}

/* MIRROR */

void mirrorTest() {
    Grid<int> grid(4, 4);
    grid[0][0] = 6;
    grid[0][1] = 1;
    grid[0][2] = 9;
    grid[0][3] = 4;
    grid[1][0] = -2;
    grid[1][1] = 5;
    grid[1][2] = 8;
    grid[1][3] = 12;
    grid[2][0] = 14;
    grid[2][1] = 39;
    grid[2][2] = -6;
    grid[2][3] = 18;
    grid[3][0] = 21;
    grid[3][1] = 55;
    grid[3][2] = 73;
    grid[3][3] = 3;

    mirror(grid);
    cout << "MIRROR:" << endl << grid << endl;
}

void mirror(Grid<int> &grid) {
    for (int r = 0; r < grid.numRows(); r++) {
        // start at r+1 rather than 0
        // to avoid double-swapping
        for (int c = r + 1; c < grid.numCols(); c++) {
            int temp = grid[r][c];
            grid[r][c] = grid[c][r];
            grid[c][r] = temp;
        }
    }
}

/* PLUS SUM */

void plusSumTest() {
    Grid<int> grid(3, 3);
    for (int r = 0; r < grid.nRows; r++) {
        for (int c = 0; c < grid.nCols; c++) {
            grid[r][c] = r*3 + c + 1;
        }
    }
    cout << "PLUSSUM:" << endl << plusSum(grid, 1, 1) << endl;
}

int plusSum(Grid<int> &grid, int row, int col) {
    int sum = 0;
    for (int c = col - 1; c <= col + 1; c++) {
        sum += grid[row][c];
    }
    for (int r = row - 1; r <= row + 1; r++) {
        sum += grid[r][col];
    }
    sum -= grid[row][col]; // subtract center because it was added twice
    return sum;
}

/* STRETCH */

void stretchTest() {
    Vector<int> v;
    v.add(18);
    v.add(7);
    v.add(4);
    v.add(24);
    v.add(11);

    stretch(v);
    cout << "STRETCH:" << endl << v << endl;
}

void stretch(Vector<int> &v) {
    int size = v.size();
    for (int i = 0; i < size * 2; i += 2) {
        int n = v[i];
        v[i] = n / 2 + n % 2;
        v.insert(i + 1, n / 2);
    }
}

/* CONSECUTIVE DUPLICATES */

void consecutiveDuplicatesTest() {
    Vector<int> v;
    v.add(1);
    v.add(2);
    v.add(2);
    v.add(3);
    v.add(2);
    v.add(2);
    v.add(3);

    removeConsecutiveDuplicates(v);
    cout << "REMOVECONSECUTIVEDUPLICATES:" << endl << v << endl;
}

void removeConsecutiveDuplicates(Vector<int> &v) {
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i] == v[i + 1]) {
            v.remove(i + 1);
            i--;
        }
    }
}

/* MYSTERY */

void mysteryTest() {
    cout << "MYSTERY:" << endl;
    Stack<int> s;
    for (int i = 0; i < 6; i++) {
        s.add(i+1);
    }

    collectionMystery(s);

    s.clear();

    s.add(42);
    s.add(3);
    s.add(12);
    s.add(15);
    s.add(9);
    s.add(71);
    s.add(88);

    collectionMystery(s);

    s.clear();

    s.add(65);
    s.add(30);
    s.add(10);
    s.add(20);
    s.add(45);
    s.add(55);
    s.add(6);
    s.add(1);

    collectionMystery(s);
}

void collectionMystery(Stack<int>& s) {
    Queue<int> q;
    Stack<int> s2;
    while (!s.isEmpty()) {
        if (s.peek() % 2 == 0) {
            q.enqueue(s.pop());
        } else {
            s2.push(s.pop());
        } }
    while (!q.isEmpty()) {
        s.push(q.dequeue());
    }
    while (!s2.isEmpty()) {
        s.push(s2.pop());
    }
    cout << s << endl;
}

/* DUPLICATE ELEMENTS */

void duplicateElementsTest() {
    Queue<int> q;
    for (int i = 0; i < 3; i++) {
        q.add(i+1);
    }

    duplicateElements(q);
    cout << "DUPLICATEELEMENTS:" << endl << q << endl;
}

void duplicateElements(Queue<int>& q) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
        int n = q.dequeue();
        q.enqueue(n);
        q.enqueue(n);
    }
}

/* SPLIT STACK */

void splitStackTest() {
    // {4, 0, -1, 5, -6, -3, 2, 7}
    Stack<int> s;
    s.add(4);
    s.add(0);
    s.add(-1);
    s.add(5);
    s.add(-6);
    s.add(-3);
    s.add(2);
    s.add(7);

    splitStack(s);
    cout << "SPLITSTACK" << s << endl;
}

void splitStack(Stack<int> &stack) {
    Queue<int> queue;
    while (!stack.isEmpty()) {
        queue.enqueue(stack.pop());
    }
    int size = queue.size();
    for (int i = 0; i < size; i++) {
        int num = queue.dequeue();
        if (num >= 0) {
            queue.enqueue(num);
        } else {
            stack.push(num);
        }
    }
    while (!queue.isEmpty()) {
        stack.push(queue.dequeue());
    }
}

/* KEITH NUMBERS */

void keithNumbersTest() {
    cout << "KEITHNUMBERS:" << endl;
    findKeithNumbers(1, 50);
}

bool findKeithSequence(Vector<int> &sequence, int n) {
    int sum = 0;
    int digits = n;
    int numDigits = 0;

    while (digits > 0) {
        int digit = digits % 10;
        sum += digit;
        sequence.insert(0, digit);
        digits /= 10;
        numDigits++;
    }

    while (sequence[sequence.size() - 1] < n) {
        sequence.add(sum);
        sum = sum - sequence[sequence.size() - numDigits - 1] + sum;
    }
    return sequence[sequence.size() - 1] == n;
}

void findKeithNumbers(int min, int max) {
    for (int n = min; n <= max; n++) {
        Vector<int> sequence;
        if (findKeithSequence(sequence, n)) {
            cout << n << ": " << sequence << endl;
        }
    }
}

/* AVERAGE IN FILE */

void averageInFileTest() {
    cout << "AVERAGEINFILE:" << endl << averageValueInFile("nums.txt") << endl;
}

double averageValueInFile(string filename) {
    int count = 0;
    double sum = 0.0;
    ifstream input;
    openFile(input, filename);
    string line;
    while (getline(input, line)) {
        double val = stringToReal(line);
        count++;
        sum += val;
    }

    return 1.0 * sum / count;
}

/* NAME DIAMOND */

void nameDiamondTest() {
    cout << "NAMEDIAMOND:" << endl;
    nameDiamond("CHRIS");
}

void nameDiamond(string s) {
    int len = (int)s.length(); // cast length to int to avoid warning // print top half of diamond
    for (int i = 1; i <= len; i++) {
        cout << s.substr(0, i) << endl; }
    // print bottom half of diamond
    for (int i = 1; i < len; i++) {
        // indent with spaces
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        cout << s.substr(i, len - i) << endl;
    }
}
