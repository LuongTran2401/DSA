#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

TreeNode* buildTree(const vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < arr.size()) {
        TreeNode* node = q.front(); q.pop();
        if (arr[i] != -1) {
            node->left = new TreeNode(arr[i]);
            q.push(node->left);
        }
        i++;
        if (i < arr.size() && arr[i] != -1) {
            node->right = new TreeNode(arr[i]);
            q.push(node->right);
        }
        i++;
    }

    return root;
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    if (!root) return result;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        TreeNode* rightmost = nullptr;
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front(); q.pop();
            rightmost = node;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(rightmost->val);
    }

    return result;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nodes;
        int x;
        while (ss >> x) nodes.push_back(x);

        TreeNode* root = buildTree(nodes);
        vector<int> view = rightSideView(root);

        for (int val : view) cout << val << " ";
        cout << endl;
    }

    return 0;
}
