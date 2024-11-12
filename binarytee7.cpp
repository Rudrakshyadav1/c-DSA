#include <iostream>
#include <cmath> 
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

bool checkIdentical(node* r1, node* r2) {
    if (r1 == nullptr && r2 == nullptr) {
        return true;
    }
    if (r1 == nullptr || r2 == nullptr) {
        return false;
    }
    if (r1->data != r2->data) {
        return false;
    }
    bool leftIdentical = checkIdentical(r1->left, r2->left);
    bool rightIdentical = checkIdentical(r1->right, r2->right);
    
    return leftIdentical && rightIdentical;
}

int main() {
    node* root1 = nullptr;
    node* root2 = nullptr;
    cout << "Building first tree:\n";
    root1 = BuiltBinaryTree(root1);
    cout << "Building second tree:\n";
    root2 = BuiltBinaryTree(root2);
    if (checkIdentical(root1, root2)) {
        cout << "The trees are identical." << endl;
    } else {
        cout << "The trees are not identical." << endl;
    }
}
