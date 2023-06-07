//
// Created by 김민석 on 2023/06/07.
//
#include <iostream>
#include <queue>

using namespace std;

struct compare {
    bool operator()(const int &a, const int &b) {
        int abs_a = abs(a);
        int abs_b = abs(b);

        if (abs_a > abs_b)
            return true;
        else if (abs_a == abs_b)
            return a > b;
        else
            return false;
    };
};

priority_queue<int, vector<int>, compare> q;
int total, input, current_size;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> total;

    for (int i = 0; i < total; i++) {
        cin >> input;

        if (input == 0) {
            if (current_size == 0)
                cout << "0\n";
            else {
                cout << q.top() << "\n";
                q.pop();
                --current_size;
            }
        } else {
            q.push(input);
            ++current_size;
        }
    }

    return 0;
}
