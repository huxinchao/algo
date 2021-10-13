#include <bits/stdc++.h>
using namespace std;

int main() { 
    vector<int> vec;
    vec.push_back(1);
    const std::vector<int>::iterator iter = vec.begin();
    *iter = 0;
    std::vector<int>::const_iterator cIter = vec.begin();
    ++cIter;
    

    return 0;
}