#include<iostream>
using namespace std;
int add(int a[],int s){
    if(s==0){
        return 0;
    }
    if(s==1){
        return a[0];
    }
    else{
        return a[0]+add(a+1,s-1);
    }

}
int main(){
    int a[]={1,2,3,10};
    int s=sizeof(a)/sizeof(a[0]);
    cout<<add(a,s);
} 