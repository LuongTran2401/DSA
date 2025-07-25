#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

void printPaths(Node* root, vector<int>& path) {
    if (!root) return;
    path.push_back(root->val);
    if (!root->left && !root->right) {
        for (int v : path) cout << v << " ";
        cout << endl;
    } else {
        printPaths(root->left, path);
        printPaths(root->right, path);
    }
    path.pop_back();
}

Node* buildTree(const vector<int>& values) {
    if (values.empty() || values[0] == -1) return NULL;
    Node* root = new Node(values[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < values.size()) {
        Node* current = q.front(); q.pop();
        if (i < values.size() && values[i] != -1) {
            current->left = new Node(values[i]);
            q.push(current->left);
        }
        i++;
        if (i < values.size() && values[i] != -1) {
            current->right = new Node(values[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> values;
        int x;
        while (ss >> x) values.push_back(x);
        Node* root = buildTree(values);
        vector<int> path;
        printPaths(root, path);
    }
    return 0;
}
