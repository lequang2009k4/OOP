#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ArrayManipulator {
private:
    vector<int> arr;

public:
    ArrayManipulator(int n) : arr(n, 0) {}

    void applyTransformation(int u, int v, int k) {
        arr[u - 1] += k;
        if (v < arr.size()) {
            arr[v] -= k;
        }
    }

    void processTransformations() {
        for (int i = 1; i < arr.size(); ++i) {
            arr[i] += arr[i - 1];
        }
    }

    int getMaxInRange(int u, int v) {
        return *max_element(arr.begin() + u - 1, arr.begin() + v);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    ArrayManipulator arrayManipulator(n);

    for (int i = 0; i < m; ++i) {
        int u, v, k;
        cin >> u >> v >> k;
        arrayManipulator.applyTransformation(u, v, k);
    }

    arrayManipulator.processTransformations();

    int p;
    cin >> p;

    for (int i = 0; i < p; ++i) {
        int u, v;
        cin >> u >> v;
        int result = arrayManipulator.getMaxInRange(u, v);
        cout << result << '\n';
    }

    return 0;
}

