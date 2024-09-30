#include <iostream>
using namespace std;
int sqrtmain(int n ){
    int s=0;
    int e=n;
    int ans=-1;
    while(s<=e){

        int mid=s+(e-s)/2;
        int sq=mid*mid;
        if(n==0){
            return 0;
        }
        if(n==sq){
            return mid;
          
        }
        else if(n<sq){
            e=mid-1;
            ans=mid-1;}
        else{
            ans=mid-1;
            s=mid+1;}
        
    }
    return ans;
}
double precission(int n,int p,int z){
    double f=1.0;
    double k=0.00;
    for(int i=0;i<z;i++){
        f=f/10;
        for(double j=p;j<n;j+=f){
            if(j*j<=n){
                k=j;
               
            }
            else{
                break;
            }
        }
    }
    return k;

}

int main(){
    int n;
    cout<<"enter n:";
    cin>>n;
    int p=sqrtmain(n);
    int z;
    cout<<"TILL HOW MANY DECIMAL PLACES DO YOU WANT OUTPUT :";
    cin>>z;
    cout<<"squareroot=="<<precission(n,p,z);

}