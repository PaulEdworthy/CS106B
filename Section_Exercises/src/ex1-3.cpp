/* 3. Stretch
Write a function named stretch that accepts a reference to a vector of integers as a parameter and
modifies it to be twice as large, replacing every integer with a pair of integers, each half the
original. If a number in the original vector is odd, then the first number in the new pair should be
one higher than the second so that the sum equals the original number. For example, passing the
vectior {18, 7, 4, 24, 11} should modify the vector to contain {9, 9, 4, 3, 2, 2, 12,
12, 6, 5}. */

#include <iostream>
#include "vector.h"

void stretch(Vector<int>& vec)
{
    int size = vec.size() * 2;
    for (int i = 0; i < size; i++)
    {
        int n = vec[i];
        vec[i] = n / 2;
        vec.insert(i + 1, n / 2);
    }
}

int main()
{
    Vector<int> vec{};
    vec.add(18);
    vec.add(7);
    vec.add(4);
    vec.add(24);
    vec.add(11);
    
    stretch(vec);
    return 0;
}
