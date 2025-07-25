#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubArraySum(const vector<int>& a) {
    int current_max = a[0], global_max = a[0];
    for (size_t i = 1; i < a.size(); ++i) {
        current_max = max(a[i], current_max + a[i]);
        global_max = max(global_max, current_max);
    }
    return global_max;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        cout << maxSubArraySum(A) << endl;
    }
    return 0;
}
