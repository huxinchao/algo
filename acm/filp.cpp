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
int mp[Maxn][Maxn];//原始地图
int tmp[Maxn][Maxn];//当前操作的地图
int ans[Maxn][Maxn];//最优解地图
int dt[][2] = { { -1, 0 }, { 1, 0 }, { 0, 0 }, { 0, -1 }, { 0, 1 } };//5个方向
int getcolor(int x,int y)//得到(x,y)的颜色
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
    for(int i=1; i<n; i++)//从第二行开始检查是否需要翻转
        for(int j=0; j<m; j++)
            if(getcolor(i-1,j))
                tmp[i][j]=1;
    for(int i=0; i<m; i++)//检查最后一行是否全为0
        if(getcolor(n-1,i))
            return INF;
    for(int i=0; i<n; i++)//统计翻转次数
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
    for(int i=0; i<1<<m; i++)//按照字典序枚举第一行所以翻转可能
    {
        MEM(tmp,0);//初始化地图
        for(int j=0; j<m; j++)
            tmp[0][j]= i>>(m-(j+1)) & 1;//第一行的状态
        int sum=solve();//翻转的次数
        if(sum<result)//更新地图
        {
            result=sum;
            memcpy(ans,tmp,sizeof tmp);//tmp数组复制到ans
        }
    }
    if(result==INF)
        cout<<"IMPOSSIBLE"<<endl;
    else//输出
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                cout<<ans[i][j]<<" ";
            cout<<endl;
        }
    }
}
