//62
//62
#include<bits/stdc++.h>
using namespace std;
map<char,string>mymap;
class HuffmanNode
{
      public:
      char data;
      int freq;
      HuffmanNode* left;
      HuffmanNode* right;
      HuffmanNode(char c, int f)
      {
            data = c;
            freq = f;
            left = right = NULL;
      }
};
class Compare {
public:
    bool operator()(HuffmanNode* a,
                    HuffmanNode* b)
    {
        // Defining priority on
        // the basis of frequency
        return a->freq > b->freq;
    }
};
HuffmanNode* generateTree(priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq)
{
      while(pq.size()!=1)
      {
            HuffmanNode* left = pq.top();
            pq.pop();
            HuffmanNode* right = pq.top();
            pq.pop();
            HuffmanNode* node = new HuffmanNode('$',left->freq+right->freq);
            node->left = left;
            node->right = right;
            pq.push(node);
      }
      return pq.top();
}
void printtab(HuffmanNode* root, int arr[],int top)
{
      if(root->left)
      {
            arr[top]=0;
            printtab(root->left,arr,top+1);
      }
      if(root->right)
      {
            arr[top]=1;
            printtab(root->right,arr,top+1);
      }
      if(!root->left && !root->right)
      {
            for(int i = 0; i < top; i++)
            {
                  char c = '0'+arr[i];
                  mymap[root->data]+=c;
            }
      }
}
void HuffmanCode(char data[], int freq[], int size)
{
      priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;
      for(int i = 0; i < size; i++)
      {
            HuffmanNode* temp = new HuffmanNode(data[i], freq[i]);
            pq.push(temp);
      }
      int arr[100];
      HuffmanNode* root = generateTree(pq);
      printtab(root,arr,0);
}
int main()
{
      int n;
      cin >> n;
      char data[n];
      int freq[n];
      for(int i = 0; i < n; i++)
      {
            cin >> data[i]>>freq[i];
      }
      data[n]='\0';
      
      HuffmanCode(data,freq,n);
      for(auto i : mymap)
      {
            cout<< i.first<<" "<<i.second<<endl;
      }
}