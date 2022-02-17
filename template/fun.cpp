#include <iostream>
#include <functional>
#include <algorithm>
#include <iterator>
#include <set>

namespace std {
    template<typename T>
    ostream& operator << (ostream& os, const set<T> &l) {
        if(!l.empty()) {
            set<T>::const_iterator i = l.end();
            copy(l.begin(), --i, ostream_iterator<T>(cout, ", "));
            cout << *i;
        }
        return os;
    }
}

int main() {
    std::set<int> s = {1,2,3};
    std::cout << s << std::endl;
    
    
   
    
}