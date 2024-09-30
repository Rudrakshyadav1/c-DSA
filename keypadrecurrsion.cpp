#include<iostream>
#include<vector>
using namespace std;
void powerset(string map[],int index,string n,string output,vector<string> &ans){
    while(index>=n.length()){
        ans.push_back(output);
        return;
    }
    int num= n[index]-'0';
    string val=map[num];
    for(int i=0;i<val.length();i++){
        output.push_back(val[i]);
        powerset(map,index+1,n,output,ans);
        output.pop_back();
    }
    
}
int main(){
    vector<string> ans;
    string n;
    cout<<"Enter a number:";
    cin>>n;
    string output="";
    string map[9]={"","","abc","def","ghi","jkl","mno","pqr","rst"};
    int index=0;
    powerset(map,index,n,output,ans);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
}}