#include <iostream>
#include <deque>
#include <vector>
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
vector<int> spiralTraversal(node* root) {
    vector<int> result;
    if (root == nullptr) {
        return result;
    }
    deque<node*> q;  
    q.push_back(root);
    bool leftToRight = true; 
    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> levelNodes;  
        for (int i = 0; i < levelSize; i++) {
            node* currentNode = q.front();
            q.pop_front();
            levelNodes.push_back(currentNode->data);
            if (currentNode->left) {
                q.push_back(currentNode->left);
            }
            if (currentNode->right) {
                q.push_back(currentNode->right);
            }
        }
        if (!leftToRight) {
            vector<int> reversedLevelNodes;
            for (int i = levelNodes.size() - 1; i >= 0; i--) {
                reversedLevelNodes.push_back(levelNodes[i]);
            }
            levelNodes = reversedLevelNodes;
        }
        result.insert(result.end(), levelNodes.begin(), levelNodes.end());
        leftToRight = !leftToRight;
    }

    return result;
}

int main() {
    node* root = BuildBinaryTree(); 
    vector<int> result = spiralTraversal(root); 
    cout << "Spiral (Zigzag) Order Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

