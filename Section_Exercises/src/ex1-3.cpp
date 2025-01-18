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
