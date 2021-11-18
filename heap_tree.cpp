#include <bits/stdc++.h>

using namespace std;

class HeapTree {
public:
    vector<int> MHT = { -1 };
    int size = 0;

    void add(int value) {
        MHT.push_back(value);
        size++;
        shift_up(size);
    }

    void shift_up(int pos) {
        if (pos < 1 || pos > size || pos >> 1 < 1) return;
        if (MHT[pos] > MHT[pos >> 1]) swap(MHT[pos], MHT[pos >> 1]);
        // left_shift: << = * 2
        // right_shift: >> = / 2 
        shift_up(pos >> 1);
    }

    void remove(int key) {
        for (int i = 0; i <= size; i++) {
            if (MHT[i] == key) {
                MHT[i] = MHT[size];
                MHT.resize(size);
                size--;
                shift_down(i);
                break;
            }
        }
    }

    void shift_down(int pos) {
        if (pos < 1 || pos > size || pos << 1 > size) return;
        int chi = pos << 1;
        int m = max_of_br(MHT[pos], MHT[chi], MHT[chi + 1]);
        if (m == MHT[pos]) return;
        else if (m == MHT[chi]) {
            swap(MHT[pos], MHT[chi]);
            shift_down(chi);
        } else if (m == MHT[chi + 1]) {
            swap(MHT[pos], MHT[chi + 1]);
            shift_down(chi + 1);
        }
    }

    void print() {
        for (int i = 1; i <= size / 2; i++) {
            cout << MHT[i] << " [ " << MHT[i * 2];
            if (i * 2 + 1 <= size) cout <<  " , " << MHT[i * 2 + 1];
            cout << " ]" << endl;
        }
    }

    int max_of_br(int a, int b, int c) {
    return max(a, max(b, c));
}
};

int main() {
    HeapTree ht;

    ht.add(2);
    ht.add(1);
    ht.add(10);
    ht.add(6);
    ht.add(3);
    ht.add(8);
    ht.add(7);
    ht.add(13);
    ht.add(20);
        
    ht.print();
    cout << "=====================" << endl;

    ht.add(14);
    ht.add(0);
    ht.add(35);

    ht.print();
    cout << "=====================" << endl;

    ht.remove(6);
    ht.print();
    cout << "=====================" << endl;

    ht.remove(13);
    ht.print();
    cout << "=====================" << endl;

    ht.remove(35);
    ht.print();
    cout << "=====================" << endl;

    ht.add(15);
    ht.print();
    
    return 0;
}