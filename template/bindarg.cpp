#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>

template<typename Ite, typename T>
Ite remove_less_than(Ite begin, Ite end, const T &v) {
    using namespace std;
    typedef typename iterator_traits<Ite>::value_type value_type;
    return remove_if(begin, end, bind2nd(less<value_type>(), v));
}

template<typename T>
T my_min(T a, T b) {
    return a < b ? a : b;
}

template<typename Ite0, typename Ite1, typename T>
void denoise(Ite0 begin0, Ite0 end0, Ite1 begin1, const T &threshold) {
    using namespace std;
    typedef typename iterator_traits<Ite0>::value_type value_type;
    transform(begin0, end0, begin1, bind2nd(ptr_fun(my_min<T>), threshold));
}


int main() {
    using namespace std;
    vector<int> ar = {1,2,3,4,5};
    remove_less_than(ar.begin(), ar.end(), 3);
    for(int &i : ar) {
        cout << i << endl;
    }
}

