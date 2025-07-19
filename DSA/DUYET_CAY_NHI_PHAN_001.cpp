#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& a) {
    if (a.empty() || a[0] == -1) return NULL;

    TreeNode* root = new TreeNode(a[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < a.size()) {
        TreeNode* curr = q.front(); q.pop();
        if (i < a.size() && a[i] != -1) {
            curr->left = new TreeNode(a[i]);
            q.push(curr->left);
        }
        i++;
        if (i < a.size() && a[i] != -1) {
            curr->right = new TreeNode(a[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

void levelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            TreeNode* node = q.front(); q.pop();
            cout << node->val << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl;
    }
}

int main() {
    int T; cin >> T;
    while (T--) {
        string line;
        cin.ignore();
        getline(cin, line);
        stringstream ss(line);
        vector<int> a;
        int x;
        while (ss >> x) {
            a.push_back(x);
        }
        TreeNode* root = buildTree(a);
        levelOrder(root);
    }
    return 0;
}
