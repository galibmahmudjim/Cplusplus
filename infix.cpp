//62
//62
//62
//62
//62
//62
#include<bits/stdc++.h>
using namespace std;
#include "debugger.h"
map <char, int> prec;
int main()
{
      prec['+']=1;
      prec['-']=1;
      prec['*']=2;
      prec['/']=2;
      string infix;
      cin >> infix;
      string prefix;
      stack<char> stak;
      for(int i = 0; i < infix.size(); i++)
      {
            if(infix[i]>='0' && infix[i]<='9') prefix+=infix[i];
            else if(infix[i]=='(') stak.push(infix[i]);
            else if(infix[i]==')')
            {
                  while(!stak.empty())
                  {
                        char sign = stak.top();
                        stak.pop();
                        if(sign=='(') break;
                        prefix+=sign;
                  }
            }
            else
            {
                  while(!stak.empty() && prec[infix[i]]<=prec[stak.top()] && infix[i]!='(' && infix[i]!=')')
                  {
                        prefix+=stak.top();
                        stak.pop();
                  }
                  stak.push(infix[i]);
            }
      }
      while(!stak.empty())
      {
            prefix+=stak.top();
            stak.pop();
      }
      stack<long long int>eval;
      for(int i = 0; i < prefix.size();i++)
      {
            if(prefix[i]>='0' && prefix[i]<='9')
            {
                  long long int temp = prefix[i]-'0';
                  eval.push(temp);
            }
            else
            {
                  long long int temp1, temp2, ans;
                  temp1 = eval.top();
                  eval.pop();
                  temp2 = eval.top();
                  eval.pop();
                  if(prefix[i]=='+') ans = temp1 + temp2;
                  else if(prefix[i]=='-') ans = temp2 - temp1;
                  else if(prefix[i]=='*') ans = temp1 * temp2;
                  else if(prefix[i]=='/') ans = temp2 / temp1;
                  eval.push(ans);
            }
      }
      cout<<eval.top()<<endl;
}