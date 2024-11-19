#include <iostream>
#include <vector> 
using namespace std;
class node{
public:
    node* left;
    node* right;
    int data;
    node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};
void BinaryTreeConstructor(node*& root){
    int n;
    cout << "Enter data to be inserted : ";
    cin >> n;
    cout << "\n";
    if (n == -1){
        return;
    }
    root = new node(n);
    cout << "Enter data for the left node of " << n << "\n";
    BinaryTreeConstructor(root->left);
    cout << "\n";
    cout << "Enter data for the right node of " << n << "\n";
    BinaryTreeConstructor(root->right);
    cout << "\n";
}
void ksums(int target_sum, int& count, vector<int>& path, node* root){
    if (root == nullptr){
        return; 
    }
    path.push_back(root->data);
    int current_sum = 0;
    for (int i = path.size() - 1; i >= 0; i--){
        current_sum += path[i];
        if (current_sum == target_sum){
            count++; 
        }
    }
    ksums(target_sum, count, path, root->left);
    ksums(target_sum, count, path, root->right);
    path.pop_back();
}
int main(){
    int sum;
    cout<<"Enter value to be entered:";
    cin>>sum;
    cout<<"\n";
    int count=0;
    vector<int>path;
    node*root;
    root=nullptr;
    BinaryTreeConstructor(root);
    ksums(sum,count,path,root);
    cout<<count;
    return 0;
}