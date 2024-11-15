#include <iostream>
#include <deque>
#include <map>
#include <vector>
#include <queue>
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

node* BuildBinaryTree() {
    int data;
    cout << "Enter data to be inserted (or -1 to stop): ";
    cin >> data;

    if (data == -1) {
        return nullptr;
    }
    node* newNode = new node(data);
    cout << "Inserting elements to the left of " << data << ":\n";
    newNode->left = BuildBinaryTree();
    cout << "Inserting elements to the right of " << data << ":\n";
    newNode->right = BuildBinaryTree();
    return newNode;
}

void verticalTraversal(node* root) {
    if (root == nullptr) { 
        return;
    }
    map<int, vector<int>> verticalMap;  
    queue<pair<node*, int>> q;
    q.push({root, 0});  

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto nodePair = q.front();
            q.pop();
            node* currentNode = nodePair.first;
            int hd = nodePair.second;  
            verticalMap[hd].push_back(currentNode->data);
            if (currentNode->left) {
                q.push({currentNode->left, hd - 1});
            }
            if (currentNode->right) {
                q.push({currentNode->right, hd + 1});
            }
        }
    }
    cout << "Vertical traversal of the binary tree is:" << endl;
    for (auto& entry : verticalMap) {
        for (int val : entry.second) {
            cout << val << " ";
        }
        cout << endl;
    }
}
int main() {
    node* root = BuildBinaryTree();  
    verticalTraversal(root);  

    return 0;
}
