#include <iostream>
#include <vector>
using namespace std;
string longestprefix(vector<string>&str){
    sort(str.begin(),str.end());
    string s1=str[0];
    string s2=str[str.size()-1];
    int i=0;
    int j=0;
    string ans="";
    while(i<s1.size() && j<s2.size()){
        if(s1[i]==s2[j]){
            ans+=s1[i];
            i++;j++;
        }
        else{
            break;
        }
        }
    return ans;
}
int main(){
    int n;
    cout<<"ENTER NUMBER OF STRING YOU WANT TO ENTER:";
    cin>>n;
    vector <string> str(n);
    for(int i=0;i<n;i++){
        cin>>str[i];}
    cout<<longestprefix(str);
    return 0;

 
}