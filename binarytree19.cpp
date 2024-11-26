#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
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

node* BinaryTreeConstructor(node* root) {
    int n;
    cout << "Enter value for node (or -1 for no node): ";
    cin >> n;
    if (n == -1) {
        return nullptr;
    }
    root = new node(n);
    cout << "Enter value for the left child of " << n << ": ";
    root->left = BinaryTreeConstructor(root->left);
    cout << "Enter value for the right child of " << n << ": ";
    root->right = BinaryTreeConstructor(root->right);

    return root;
}

void buildParentMapping(node* root, unordered_map<node*, node*>& parentMap) {
    if (root == nullptr) {
        return;
    }
    if (root->left) {
        parentMap[root->left] = root;
        buildParentMapping(root->left, parentMap);
    }
    if (root->right) {
        parentMap[root->right] = root;
        buildParentMapping(root->right, parentMap);
    }
}
int burnBinaryTree(node* root, int target) {
    unordered_map<node*, node*> parentMap;
    unordered_map<node*, bool> visited; 
    node* targetNode = nullptr;
    queue<node*> q;
    buildParentMapping(root, parentMap);
    bool targetFound = false;
    q.push(root);
    while (!q.empty() && !targetFound) {
        node* current = q.front();
        q.pop();
        if (current->data == target) {
            targetNode = current;
            targetFound = true;
        }
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }

    if (!targetNode) {
        cout << "Target node not found in the tree.\n";
        return -1;
    }
    q.push(targetNode);
    visited[targetNode] = true;
    int time = 0;

    while (!q.empty()) {
        int size = q.size();
        bool fireSpread = false;
        for (int i = 0; i < size;i++) {
            node* currentNode = q.front();
            q.pop();
            if (currentNode->left && !visited[currentNode->left]) {
                visited[currentNode->left] = true;
                q.push(currentNode->left);
                fireSpread = true;
            }
            if (currentNode->right && !visited[currentNode->right]) {
                visited[currentNode->right] = true;
                q.push(currentNode->right);
                fireSpread = true;
            }
            if (parentMap.find(currentNode) != parentMap.end() &&
                !visited[parentMap[currentNode]]) {
                visited[parentMap[currentNode]] = true;
                q.push(parentMap[currentNode]);
                fireSpread = true;
            }
        }
        if (fireSpread){
            time++;
        }
    }

    return time;
}

int main() {
    node* root = nullptr;
    root = BinaryTreeConstructor(root);

    cout << "Enter the target element: ";
    int target;
    cin >> target;

    int result = burnBinaryTree(root, target);
    if (result != -1) {
        cout << "Minimum time to burn the entire tree: " << result << " seconds." << endl;
    }
    return 0;
}
