//  Filename: dfs.cpp
#include <iostream>
#include <algorithm>>
using namespace std;

int M,N;
char MAP[101][101];

void dfs(int,int);

int main() {    cin >> N >> M;
    int res = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> MAP[i][j];
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(MAP[i][j] == 'W') {
                res++;
                dfs(i,j);
            }
        }
    }
    cout << res << endl;
    return 0;    
}
void dfs(int i, int j) {
    MAP[i][j] = '.';
    for(int dx = -1; dx <= 1; dx++) {
        for(int dy = -1; dy <= 1; dy++) {
            if(i + dx >= 0 && i + dx <= N && j + dy >= 0 && j + dy <= M) {
                if(MAP[i+dx][j+dy] == 'W') {
                    dfs(i + dx, j + dy);
                }
            }
        }
    }
}

