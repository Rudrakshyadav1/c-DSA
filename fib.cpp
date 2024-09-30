//1 1 2 3 5 8 13....
#include<iostream>
using namespace std;
int fibo(int n){
    if(n==1 or n==2){
        return 1;
    }
    return fibo(n-1)+fibo(n-2);
}
int main(){
    int n;
    cout<<"enter an number:";
    cin>>n;
    cout<<fibo(n);

}