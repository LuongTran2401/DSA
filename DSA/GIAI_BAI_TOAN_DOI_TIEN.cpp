#include <iostream>
using namespace std;

int denominations[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};

int minNotes(int S) {
    int count = 0;
    for (int i = 0; i < 9 && S > 0; ++i) {
        count += S / denominations[i];
        S %= denominations[i];
    }
    return (S == 0 ? count : -1);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int S;
        cin >> S;
        cout << minNotes(S) << endl;
    }
    return 0;
}
