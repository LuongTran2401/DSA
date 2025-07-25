#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(const vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return nullptr;
    vector<TreeNode*> nodes;
    for (int val : arr) {
        nodes.push_back(val == -1 ? nullptr : new TreeNode(val));
    }

    int j = 1;
    for (int i = 0; j < arr.size(); ++i) {
        if (nodes[i] != nullptr) {
            if (j < arr.size()) nodes[i]->left = nodes[j++];
            if (j < arr.size()) nodes[i]->right = nodes[j++];
        }
    }
    return nodes[0];
}

void dfs(TreeNode* root, string path, vector<string>& result) {
    if (!root) return;
    if (!path.empty()) path += "->";
    path += to_string(root->val);
    
    if (!root->left && !root->right) {
        result.push_back(path);
        return;
    }
    
    dfs(root->left, path, result);
    dfs(root->right, path, result);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int& x : arr) cin >> x;

        TreeNode* root = buildTree(arr);
        vector<string> paths;
        dfs(root, "", paths);

        if (paths.empty()) {
            cout << "0" << endl;
        } else {
            for (const string& p : paths) {
                cout << p << endl;
            }
        }
    }
    return 0;
}
