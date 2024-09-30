#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>sol;
    int a[]={1,2,3,4,5};
    int b[]={5,6,9};
    int k=sizeof(a)/sizeof(a[0])-1;
    int l=sizeof(b)/sizeof(b[0])-1;
    int sum=0;
    int c=0;
    while(k>=0 || l>=0 || c>0){
       sum=c;
       if(k>=0) sum+=a[k--];
       if(l>=0) sum+=b[l--];
       c=sum/10;
       sum=sum%10;
       sol.push_back(sum);
    
  
    }
    if(c>0){
        sol.push_back(c);
    } 
    for(int i=sol.size()-1;i>=0;i--){
      cout<<sol[i]<<" ";
}}