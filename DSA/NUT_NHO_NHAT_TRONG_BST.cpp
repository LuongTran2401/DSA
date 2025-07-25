#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

int findMin(Node* root) {
    while (root && root->left) {
        root = root->left;
    }
    return root->data;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        Node* root = nullptr;
        for (int i = 0; i < n; ++i) {
            int val; cin >> val;
            root = insert(root, val);
        }
        cout << findMin(root) << endl;
    }
    return 0;
}
