#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
    int V;                      // Số đỉnh của đồ thị
    vector<vector<int>> adj;    // Danh sách kề của đồ thị

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);          // Khởi tạo danh sách kề cho mỗi đỉnh
    }

    // Thêm một cạnh vào đồ thị từ đỉnh u đến đỉnh v
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // Hàm đệ quy để thực hiện duyệt theo chiều sâu (DFS)
    void DFS(int v, vector<bool>& visited) {
        visited[v] = true;
        for (int i : adj[v]) {
            if (!visited[i])
                DFS(i, visited);
        }
    }

    // Kiểm tra thành phần liên thông 
    bool isConnected() {
        vector<bool> visited(V, false);
        int i;
        // Tìm đỉnh có ít nhất một cạnh nếu có
        for (i = 0; i < V; i++) {
            if (adj[i].size() != 0)
                break;
        }
        // Nếu không có cạnh nào trong đồ thị thì đồ thị liên thông
        if (i == V)
            return true;
        // Duyệt đồ thị từ một đỉnh không đã được thăm và kiểm tra liên thông
        DFS(i, visited);
        for (i = 0; i < V; i++) {
            if (visited[i] == false && adj[i].size() > 0)
                return false;
        }
        return true;
    }

    // Đếm số lượng cạnh đi ra từ một đỉnh
    int countOutDegree(int v) {
        return adj[v].size();
    }

    // Tìm chu trình Euler và in ra chu trình đó
    void eulerCycle(int u) {
        if (isConnected()) {    // Kiểm tra xem đồ thị có liên thông hay không
            stack<int> currentPath; // Stack để lưu đường đi hiện tại
            vector<int> circuit;    // Vector để lưu chu trình Euler
            currentPath.push(u);
            int currV = u;
            while (!currentPath.empty()) {
                if (countOutDegree(currV) > 0) {
                    currentPath.push(currV);
                    int nextV = adj[currV].back();  // Lấy đỉnh kề cuối cùng của đỉnh hiện tại
                    adj[currV].pop_back();          // Loại bỏ cạnh đó khỏi đồ thị
                    currV = nextV;                  // Di chuyển đến đỉnh kề đó
                }
                else {
                    circuit.push_back(currV);       // Thêm đỉnh vào chu trình Euler
                    currV = currentPath.top();      // Lấy đỉnh trên cùng của stack
                    currentPath.pop();              // Loại bỏ đỉnh đó khỏi stack
                }
            }
            // In ra chu trình Euler
            for (int i = circuit.size() - 1; i >= 0; i--)
                cout << circuit[i]+1 << " ";
        }
        else {
            cout << "Graph is not Eulerian";      // In ra thông báo nếu đồ thị không có chu trình Euler
        }
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Graph g(V);
    cout << "Enter edges (from -> to):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        u=u-1;
        v=v-1;
        g.addEdge(u, v);                        // Nhập cạnh từ bàn phím
    }

    cout << "Eulerian Circuit: ";
    g.eulerCycle(0);                            // Tìm và in ra chu trình Euler
    return 0;
}
