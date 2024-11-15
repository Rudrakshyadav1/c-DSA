#include<iostream>
#include<queue>
#include<map>
#include<utility> 
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int data) {
        this->data = data;
        left = right = nullptr;
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
void topviewtraversal(node* root) {
    if (root == nullptr) {
        return;
    }
    queue<pair<node*, int>> q;
    map<int, int> topmap;  
    q.push({root, 0});

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        node* currentNode = current.first;
        int hd = current.second; 
        if (topmap.find(hd) == topmap.end()) {
            topmap[hd] = currentNode->data;
        }
        if (currentNode->left) {
            q.push({currentNode->left, hd - 1});
        }
        if (currentNode->right) {
            q.push({currentNode->right, hd + 1});
        }
    }
    for (auto i : topmap) {
        cout << i.second << " ";  
    }
    cout << endl;
}

int main() {
    node* root = nullptr;
    root = BuiltBinaryTree(root);
    cout << "Top view of the binary tree: ";
    topviewtraversal(root);
    return 0;
}
