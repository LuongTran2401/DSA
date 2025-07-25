#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll mergeAndCount(vector<ll>& arr, vector<ll>& temp, int left, int mid, int right) {
    ll inv_count = 0;
    int i = left, j = mid, k = left;
    while (i < mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += mid - i; 
        }
    }
    while (i < mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    for (int p = left; p <= right; ++p) arr[p] = temp[p];
    return inv_count;
}

ll countInversions(vector<ll>& arr, vector<ll>& temp, int left, int right) {
    ll inv_count = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        inv_count += countInversions(arr, temp, left, mid);
        inv_count += countInversions(arr, temp, mid + 1, right);
        inv_count += mergeAndCount(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<ll> A(N), temp(N);
        for (int i = 0; i < N; ++i)
            cin >> A[i];
        cout << countInversions(A, temp, 0, N - 1) << '\n';
    }
    return 0;
}
