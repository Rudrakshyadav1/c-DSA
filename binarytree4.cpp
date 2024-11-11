#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};
node* BuiltBinaryTree(node* root) {
    int data;
    cout << "Enter data to be inserted (or -1 to stop): ";
    cin >> data;

    if (data == -1) {
        return nullptr;  
    }
    root = new node(data);  
    cout << "Inserting elements to the left of " << data << ":\n";
    root->left = BuiltBinaryTree(root->left);  
    cout << "Inserting elements to the right of " << data << ":\n";
    root->right = BuiltBinaryTree(root->right); 
    return root; 
};
int heightOfBinarytree(node*root){
    if(root ==nullptr){
        return 0;
    }
    int leftheight=heightOfBinarytree(root->left);
    int rightheight=heightOfBinarytree(root->right);
    int ans=max(leftheight,rightheight)+1;
    return ans;
}

int main(){
    node*root=nullptr;
    root=BuiltBinaryTree(root);
    cout<<heightOfBinarytree(root);
}