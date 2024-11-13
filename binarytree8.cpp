#include <iostream>
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

// Function to build the binary tree
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
pair<bool, int> isSumTree(node* root) {
    if (root == nullptr) {
        return make_pair(true, 0);
    }
    if (root->left == nullptr && root->right == nullptr) {
        return make_pair(true, root->data);
    }
    pair<bool, int> leftSum = isSumTree(root->left);

    pair<bool, int> rightSum = isSumTree(root->right);
    if (!leftSum.first || !rightSum.first) {
        return make_pair(false, 0);
    }
    int sum = leftSum.second + rightSum.second;
    if (root->data == sum) {
        return make_pair(true, root->data + sum);  
    } else {
        return make_pair(false, 0); 
    }
}
int main() {
    node* root = nullptr;
    root = BuiltBinaryTree(root);
    pair<bool, int> result = isSumTree(root);
    
    if (result.first) {
        cout << "The tree is a Sum Tree.\n";
    } else {
        cout << "The tree is not a Sum Tree.\n";
    }
    
    return 0;
}
