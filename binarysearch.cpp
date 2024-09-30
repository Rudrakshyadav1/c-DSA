#include <iostream>
using namespace std;
int main(){
    int a[]={1,3,4,5,6,10};
    cout<<"enter element to be checked:";
    int n;
    int p=sizeof(a)/4;
    cin>>n;
    int s=0;
    int e=p-1;
    while(s<=e){
        int mid= s+(e-s)/2;
        if(a[mid]==n){
            cout<<"yes";
            return 0;
            
        }
        else if (a[mid]<n){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    
    }
    cout<<"nah!! not available!!!";

}
