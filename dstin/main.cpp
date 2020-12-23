#include <iostream>
#include <vector>
#include <string.h>
#include <bitset>
#include <stack>
#include "obj_basic.h"
using namespace std;



int main() {
    int ar[] = {10,3,7,4,12};
    stack<int> sta;

    for(int i = 0; i < 5; i++) {
        if(sta.empty() || sta.top() >= ar[i]) {
            sta.push(ar[i]);
        } else {
            while(!sta.empty() && sta.top() < ar[i]) {
                sta.pop();
            }
            sta.push(ar[i]);
        }

    }

    while(!sta.empty()) {
        cout << sta.top() << endl;
        sta.pop();
    }

    

    


}

/*
0000 0110
1111 1001

*/