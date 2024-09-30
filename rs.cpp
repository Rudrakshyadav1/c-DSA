//small letters
#include<iostream>
#include <vector>
#include<string>
using namespace std;
string sort(string str){
    vector <int>fm(26,0);
    for(int i=0;i<str.size();i++){
        int index= str[i]-'a';
        fm[index]++;}
    int j=0;
    for(int i=0;i<26;i++){
        while(fm[i]--){
            str[j++]=char(i+'a');
            
        }
    }
    return str;
}
int main(){
    string str;
    cout<<"ENTER THE DESIRED STRING:";
    cin>>str;
    cout<<"sorted string:::"<<sort(str);
}
