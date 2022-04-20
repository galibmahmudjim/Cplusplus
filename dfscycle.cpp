//62
//62
//62
//62
//62
#include<bits/stdc++.h>
using namespace std;
#include "debugger.h"
vector<int> graph[200000];
vector<int>parent;
vector<bool>visited(100000,false);
int node;
int cycle_start, cycle_end;
void edge(int a, int b)
{
      graph[a].push_back(b);
      graph[b].push_back(a);
}

bool dfs(int u, int par)
{
      visited[u]=true;
      for(auto i : graph[u])
      {
            if(i==par) continue;
            if(visited[i])
            {
                  cycle_end=u;
                  cycle_start=i;
                  return true;
            }
            parent[i]=u;
            if(dfs(i,parent[i]))
            return true;
      }
      return false;
}

void find_cycle()
{
      cycle_start=-1;
      parent.assign(node,-1);
      for(int i = 0; i < node; i++)
      {
            if(!visited[i] && dfs(i,parent[i]))
            break;
      }
      if(cycle_start==-1)
      cout<<"No\n";
      else
      {
            vector<int>cycle;
            cycle.push_back(cycle_start);
            for(int i = cycle_end; i!=cycle_start;i=parent[i])
            {
                  cycle.push_back(i);
            }
            cout<<"Yes\n";
            reverse(cycle.begin(),cycle.end());
            //for(auto i : cycle)
            //cout<<i<<" ";
            //cout<<endl;
      }
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
      find_cycle();
}


// int n;
// vector<vector<int>> adj;
// vector<char> color;
// vector<int> parent;
// int cycle_start, cycle_end;

// bool dfs(int v) {
//     color[v] = 1;
//     for (int u : adj[v]) {
//         if (color[u] == 0) {
//             parent[u] = v;
//             if (dfs(u))
//                 return true;
//         } else if (color[u] == 1) {
//             cycle_end = v;
//             cycle_start = u;
//             return true;
//         }
//     }
//     color[v] = 2;
//     return false;
// }

// void find_cycle() {
//     color.assign(n, 0);
//     parent.assign(n, -1);
//     cycle_start = -1;

//     for (int v = 0; v < n; v++) {
//         if (color[v] == 0 && dfs(v))
//             break;
//     }

//     if (cycle_start == -1) {
//         cout << "Acyclic" << endl;
//     } else {
//         vector<int> cycle;
//         cycle.push_back(cycle_start);
//         for (int v = cycle_end; v != cycle_start; v = parent[v])
//             cycle.push_back(v);
//         cycle.push_back(cycle_start);
//         reverse(cycle.begin(), cycle.end());

//         cout << "Cycle found: ";
//         for (int v : cycle)
//             cout << v << " ";
//         cout << endl;
//     }
// }
