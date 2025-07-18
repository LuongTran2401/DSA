#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void buildTree(Node* &root, map<int, Node*> &nodes, int u, int v, char ch) {
    if (nodes.find(u) == nodes.end()) {
        nodes[u] = new Node(u);
        if (root == NULL) root = nodes[u];
    }
    Node* parent = nodes[u];
    Node* child = new Node(v);
    if (ch == 'L') parent->left = child;
    else parent->right = child;
    nodes[v] = child;
}

void spiralOrder(Node* root) {
    if (!root) return;
    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty() || !s2.empty()) {
        while (!s1.empty()) {
            Node* cur = s1.top(); s1.pop();
            cout << cur->data << " ";
            if (cur->left) s2.push(cur->left);
            if (cur->right) s2.push(cur->right);
        }
        while (!s2.empty()) {
            Node* cur = s2.top(); s2.pop();
            cout << cur->data << " ";
            if (cur->right) s1.push(cur->right);
            if (cur->left) s1.push(cur->left);
        }
    }
    cout << '\n';
}

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        map<int, Node*> nodes;
        Node* root = NULL;
        set<int> child;
        for (int i = 0; i < n; ++i) {
            int u, v; char ch;
            cin >> u >> v >> ch;
            buildTree(root, nodes, u, v, ch);
            child.insert(v);
        }
        if (root == NULL) {
            for (auto& it : nodes) {
                if (child.find(it.first) == child.end()) {
                    root = it.second;
                    break;
                }
            }
        }
        spiralOrder(root);
    }
    return 0;
}
