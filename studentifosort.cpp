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

class Student
{
      public:
      string name;
      int roll;
      double cgpa;
      int marks;
      Student()
      {

      }
      Student(string name, int roll, double cgpa, int marks)
      {
            this->name=name;
            this->cgpa=cgpa;
            this->marks=marks;
            this->roll=roll;
      }
};
Student students[100010];
bool cmp(Student a, Student b)
{
      if(a.cgpa!=b.cgpa) return a.cgpa>b.cgpa;
      else if(a.marks!=b.marks) return a.marks>b.marks;
      else if(a.roll!=b.roll) return a.roll<b.roll;
      else if(a.name!=b.name) return a.name<b.name;
      else return a.cgpa<=b.cgpa;
}
void marge( int left, int mid, int right)
{
      int l = mid-left+1;
      int r =right-mid;
      Student Left[l];
      Student Right[r];
      for(int i = 0; i < l; i++)
      {
            Left[i] = students[left+i];
      }
      for(int i = 0; i < r;i++)
      {
            Right[i]=students[mid+i+1];
      }
      int i = 0;
      int j = 0;
      int k = left;
      while(i<l && j<r)
      {
            if(cmp(Right[j],Left[i]))
            {
                  students[k]=Right[j];
                  j++;
            }
            else
            {
                  students[k]=Left[i];
                  i++;
            }
            k++;
      }
      while(i<l)
      {
            students[k++]=Left[i++];
      }
      while(j<r)
      {
            students[k++]=Right[j++];
      }
}
void margesort(int l, int r)
{
      if(l>=r) return;
      int mid =l + (r-l)/2;
      margesort(l,mid);
      margesort(mid+1,r);
      marge( l, mid, r);
}
int main()
{
      int n;
      cin >> n;
      int temp = n;
      for(int i = 0; i < n; i++)
      {
            cin>>students[i].name >>students[i].roll>>students[i].cgpa>>students[i].marks;
      }
      sort(students,students+n,cmp);
      for(int i = 0; i < n; i++)
      {
            printf("%d %s",i+1,students[i].name.c_str());
            printf(" %d %.2lf %d\n",students[i].roll,students[i].cgpa,students[i].marks);
      }
}