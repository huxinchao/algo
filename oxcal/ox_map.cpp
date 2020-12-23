#include <unordered_map>
using namespace std;

unordered_map<char,int> OX_MAP;

void initial_ox_map() {
    char line_a[10] = {
        '1','2','3','4','5','6','7','8','9','0'
    };

    for(int i = 0; i < 10; i++) {
        OX_MAP[line_a[i]] = i + 1;
    }

    OX_MAP['n'] = 0;

    
    
    
   
}