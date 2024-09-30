#include <iostream>
using namespace std;
void merge(int a[],int s,int e){
    int mid=s+(e-s)/2;
    int l1_=mid-s+1;
    int l2_=e-mid;
    int *l=new int[l1_];
    int *r=new int[l2_];
    for(int i=0;i<l1_;i++){
        l[i]=a[s+i];
    }
    for(int j=0;j<l2_;j++){
        r[j]=a[mid+1+j];
    }
    int i=0;
    int j=0;
    int k=s;
    while(i<l1_ && j<l2_){
        if(l[i]<r[j]){
            a[k++]=l[i++];

        }
        else{
            a[k++]=r[j++];
        }
    }
    while(i<l1_){
        a[k++]=l[i++];
    }
    while(j<l2_){
        a[k++]=r[j++];
    }
    delete []l;
    delete []r;

}
void mergesort(int a[],int s,int e){
    int mid=s+(e-s)/2;
    if(s>=e){
        return;
    }
    else{
        //DEALING WITH LHS
        mergesort(a,s,mid);
        //dealing eith rhs
        mergesort(a,mid+1,e);
        merge(a,s,e);
        
    }


}
int main(){
    int a[6]={5,4,4,3,2,1};
    int l= sizeof(a)/sizeof(a[0]);
    int s=0;
    int e=l-1;
    mergesort(a,s,e);
    for(int i=0;i<l;i++){
        cout<<a[i];
    }
    
}