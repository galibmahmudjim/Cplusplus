//62
#include<bits/stdc++.h>
using namespace std;
class HuffmanNode
{
      public:
      string data;
      int freq;
      HuffmanNode* left;
      HuffmanNode* right;
      HuffmanNode(string str, int f, HuffmanNode* l, HuffmanNode* r)
      {
            data = str;
            freq = f;
            left = l;
            right = r;
      }
};
class cmp
{
      public:
      bool operator()(HuffmanNode* a, HuffmanNode* b)
      {
            return a->freq>b->freq;
      }
};
void travel(HuffmanNode* root, string &str, int cnt, int dr, map<string,string>&mp)
{
      if(root==NULL) return;
      if(dr==-1)
      {
            str[cnt++]+='0';
      }
      else if(dr==1)
      {
            str[cnt++]+='1';
      }
      if(root->data.size()==1)
      {
            string temp = "";
            for(int i = 0; i < cnt; i++)
            {
                  temp+=str[i];
            }
            mp[root->data]=temp;
      }
      travel(root->left,str,cnt,-1,mp);
      travel(root->right,str,cnt,1,mp);
}
map<string,int>freq;
map<string, string> res;
int main()
{
      priority_queue<HuffmanNode*,vector<HuffmanNode*>,cmp>pq;
      int n;
      cin >> n;
      getchar();
      for(int i = 0; i < n;i++)
      {
            string temp = "";
            char ch;
            scanf("%c",&ch);
            temp+=ch;
            freq[temp]++;
      }
      for(auto i : freq)
      {
            HuffmanNode* a = new HuffmanNode(i.first,i.second,NULL,NULL);
            pq.push(a);
      }
      HuffmanNode* first, *second;
      while(!pq.empty())
      {
            first=pq.top();
            pq.pop();
            if(pq.empty()) break;
            second = pq.top();
            pq.pop();
            HuffmanNode* a = new HuffmanNode(first->data+second->data,first->freq+second->freq,first,second);
            pq.push(a);
      }
      string str="";
      travel(first,str,0,0,res);
      int cnt = 0;
      for(auto i:res)
      {
            cnt+=(freq[i.first]*(i.second.size()));
      }
      cout<<cnt<<endl;
}