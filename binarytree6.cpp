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
pair<int, bool> isbalanced(node* root) {
    if (root == nullptr) {
        return make_pair(0, true);  
    }
    pair<int, bool> left = isbalanced(root->left);
    pair<int, bool> right = isbalanced(root->right);
    int heightDiff = abs(left.first - right.first);
    bool balanced = (heightDiff <= 1) && left.second && right.second;
    int height = max(left.first, right.first) + 1;
    return make_pair(height, balanced);
}
int main() {
    node* root = nullptr;
    root = BuiltBinaryTree(root);
    pair<int, bool> result = isbalanced(root);
    if (result.second) {
        cout << "The tree is balanced!" << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }


}
