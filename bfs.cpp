//62
//62
//62
//62
//62
//62
//62
//62
//62
//62
//62
//62
//62
//62
//62
//62
//62
#include<bits/stdc++.h>
using namespace std;
#include "debugger.h"
vector<int>graph[100010];
int n;
void edge(int a, int b)
{
      if(a>=n || b>=n) return;
      graph[a].push_back(b);
      graph[b].push_back(a);
}

bool bfs(int s, int d)
{
      //if(s>=n || d>=n) return false;
      vector<bool>visited(100010,false);
      queue<int>q;
      q.push(s);
      visited[s]=true;
      while (!q.empty())
      {
            int f = q.front();
            q.pop();
            if(f==d) return true;
            for(auto i : graph[f])
            {
                  if(visited[i]==false)
                  {
                        q.push(i);
                        visited[i]=true;
                  }
            }
      }
return false;
      
      
}
int main()
{

      int node;
      cin >> n >> node;
      while(node--)
      {
            string s;
            int u,v;
            cin>>s>>u>>v;
            string a = "JOIN";
            string b = "FIND";
            if(s==a)
            {
                  edge(u,v);
                  //debug(graph[u],graph[v]);
            }
            else if(s==b)
            {
                  if(bfs(u,v)) cout<<"Yes\n";
                  else cout<<"No\n";
            }
      }
}