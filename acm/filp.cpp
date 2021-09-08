#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include <sstream>
#define mod 1000000007
#define eps 1e-6
#define ll long long
#define INF 0x3f3f3f3f
#define MEM(x,y) memset(x,y,sizeof(x))
#define Maxn 20
using namespace std;
int result;
int n,m;
int mp[Maxn][Maxn];
int tmp[Maxn][Maxn];
int ans[Maxn][Maxn];
int dt[][2] = { { -1, 0 }, { 1, 0 }, { 0, 0 }, { 0, -1 }, { 0, 1 } };
int getcolor(int x,int y)
{
    int cnt=mp[x][y];
    for(int i=0; i<5; i++)
    {
        int tx=dt[i][0]+x;
        int ty=dt[i][1]+y;
        if(tx>=0&&tx<n&&ty>=0&&ty<m)
            cnt+=tmp[tx][ty];
    }
    return cnt%2;
}
int solve()
{
    int cnt=0;
    for(int i=1; i<n; i++)
        for(int j=0; j<m; j++)
            if(getcolor(i-1,j))
                tmp[i][j]=1;
    for(int i=0; i<m; i++)
        if(getcolor(n-1,i))
            return INF;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cnt+=tmp[i][j];
    return cnt;
}
int main()
{
    result=INF;
    cin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>mp[i][j];
    for(int i=0; i<1<<m; i++)
    {
        MEM(tmp,0);
        for(int j=0; j<m; j++)
            tmp[0][j]= i>>(m-(j+1)) & 1;
        int sum=solve();
        if(sum<result)
        {
            result=sum;
            memcpy(ans,tmp,sizeof tmp);
        }
    }
    if(result==INF)
        cout<<"IMPOSSIBLE"<<endl;
    else
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                cout<<ans[i][j]<<" ";
            cout<<endl;
        }
    }
}
