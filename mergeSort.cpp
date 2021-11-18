#include <iostream>
#include <vector>

using namespace std;

class MergeSort {
public:
    std::vector<int> merge(vector<int> p1, vector<int> p2) {
        std::vector<int> res;
        int n = p1.size() + p2.size();
        res.resize(n);
        int i = 0, i1 = 0, i2 = 0;
        while (i < n) {
            if (i1 >= p1.size() && i2 < p2.size()) {
                res[i] = p2[i2];
                ++i;
                ++i2;
            } else if (i1 < p1.size() && i2 >= p2.size()) {
                res[i] = p1[i1];
                ++i;
                ++i1;
            } else if (p1[i1] <= p2[i2]) {
                res[i] = p1[i1];
                ++i;
                ++i1;
            } else if (p1[i1] > p2[i2]) {
                res[i] = p2[i2];
                ++i;
                ++i2;
            }
        } 
        return res;
    }

    std::vector<int> mergeSort(vector<int> a, int left, int right) {
        // divide
        if (left > right) return {};
        if (left == right) {
            std::vector<int> singleElement = { a[left] };
            return singleElement;
        }
        int mid = (left + right) / 2;
        std::vector<int> p1 = mergeSort(a, left, mid);
        std::vector<int> p2 = mergeSort(a, mid + 1, right);
        // merge
        std::vector<int> res = merge(p1, p2);
        return res;
    }
};

int main() {
    std::vector<int> a;
    int n;
    std::cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    MergeSort* ms = new MergeSort();
    std::vector<int> r = ms -> mergeSort(a, 0, n - 1);
    for (int i = 0; i < r.size(); ++i) {
        std::cout << r[i] << " ";
    }
    return 0;
}