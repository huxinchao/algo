#include <iostream>
#include <vector>
#include <windows.h>
#include <unordered_map>

using namespace std;



int main() {
    unordered_map<int,int> MAP;
    MAP.insert({1,2});

    if(MAP.find(1) != MAP.end()) {
        cout << "FIND IT" << endl;
    }

    cin.get();

   
}



