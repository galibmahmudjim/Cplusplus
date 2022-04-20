//62
#include<bits/stdc++.h>
using namespace std;
#include "debugger.h"
vector<int>graph[10000];
set<int> v1;
set<int>v2;
vector<bool>visited(10000,false);
vector<int>color(10000);
int node;
void edge(int a, int b)
{
      graph[a].push_back(b);
      graph[b].push_back(a);
}
bool dfs(int u)
{
      for(auto i : graph[u])
      {
            if(!visited[i])
            {
                  visited[i]=true;
                  color[i]=!color[u];
                  if(!dfs(i)) return false;
            }
            else if(color[u]==color[i]) return false;
      }
      return true;
      
}
int main()
{
      int ed;
      cin >> node >> ed;
      int a, b;
      while(ed--)
      {
            cin >> a >> b;
            edge(a,b);
      }
      color[0]=0;
      if(dfs(0)) cout<<"Yes\n";
      else cout<<"No\n";
}