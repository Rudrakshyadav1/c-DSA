#include<iostream>
#include<stack>
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
}
void inordertraversal(node* root) {
    if (root == nullptr) {
        return;
    }
    inordertraversal(root->left); 
    cout << root->data << " ";  
    inordertraversal(root->right);  
}

int main() {
    node* root = nullptr;
    root = BuiltBinaryTree(root);  
    cout << "In-order traversal of the binary tree:\n";
    inordertraversal(root);  
    cout << endl;
    return 0;
}
