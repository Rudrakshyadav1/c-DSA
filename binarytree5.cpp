#include<iostream>
#include<algorithm>
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

//[diameter, height]
pair<int, int> diameter(node* root) {
    if (root == nullptr) {
        return make_pair(0, 0);
    }

    pair<int, int> left = diameter(root->left);
    pair<int, int> right = diameter(root->right);

    int leftDiameter = left.first;
    int rightDiameter = right.first;
    int leftHeight = left.second;
    int rightHeight = right.second;

    int currentDiameter = leftHeight + rightHeight + 1;
    int currentHeight = max(leftHeight, rightHeight) + 1;

    return make_pair(max(currentDiameter, max(leftDiameter, rightDiameter)), currentHeight);
}

int main() {
    node* root = nullptr;
    root = BuiltBinaryTree(root);
    pair<int, int> result = diameter(root);
    cout << "Diameter of the tree is: " << result.first << endl;
    cout << "Height of the tree is: " << result.second << endl;
}
