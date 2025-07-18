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

void levelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* cur = q.front(); q.pop();
        cout << cur->data << " ";
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
    cout << '\n';
}

int main() {
    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<int, Node*> mp;
        set<int> children;
        for (int i = 0; i < n; ++i) {
            int u, v;
            char dir;
            cin >> u >> v >> dir;
            if (!mp[u]) mp[u] = new Node(u);
            if (!mp[v]) mp[v] = new Node(v);
            if (dir == 'L') mp[u]->left = mp[v];
            else mp[u]->right = mp[v];
            children.insert(v);
        }
        Node* root = NULL;
        for (auto& p : mp) {
            if (children.find(p.first) == children.end()) {
                root = p.second;
                break;
            }
        }
        levelOrder(root);
    }
    return 0;
}
