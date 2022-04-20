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
vector<int> graph[100000];
vector<int>parent[100000];
vector<vector<int>>paths;
vector<int>path;
vector<int>dist;
int node;
void edge(int a, int b)
{
      graph[a].push_back(b);
      graph[b].push_back(a);
}
void find_paths(int u)
{
      if(u==-1)
      {
            paths.push_back(path);
            return;
      }
      for(int i : parent[u])
      {
            path.push_back(u);
            find_paths(i);
            path.pop_back();
      }
}
void bfs(int start)
{
      dist.assign(node,INT32_MAX);
      queue<int>q;
      q.push(start);
      dist[start]=0;
      parent[start]={-1};
      while(!q.empty())
      {
            int u = q.front();
            q.pop();
            for(int i : graph[u])
            {
                  if(dist[i]>dist[u]+1)
                  {
                        dist[i]=dist[u]+1;
                        q.push(i);
                        parent[i].clear();
                        parent[i].push_back(u);
                  }
                  else if (dist[i]==dist[u]+1)
                  {
                        parent[i].push_back(u);
                  }
            }
      }
}

void print( int s, int d)
{
      bfs(s);
      find_paths(d);
      string str="ZZZZZZZZZZZZZZZZZZZZZZZZ";
      for(auto i : paths)
      {
            string temp="";
            reverse(i.begin(),i.end());
            for(int u:i)
            {
                  stringstream ss;
                  ss<<u;
                  string s;
                  ss>>s;
                  temp+=s;
                  temp+=' ';
            }
            if(temp<str) str=temp;
      }
      if(str[0]=='Z') cout<<"Not Reachable\n";
      else
      cout<<str<<endl;
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
      for(int i = 0; i < node; i++)
      {
            cout<<i<<": ";
            print(0,i);
            paths.clear();
            path.clear();
      }
}
