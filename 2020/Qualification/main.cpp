#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;

const bool CHECK = true;

struct Matrix {
    vector < int > first_row;
    vector < int > shifts;
};

map < int , map < int , Matrix > > results;

void precalc(int n) {
    vector < int > numbers(n);
    for (int i = 0; i < n; ++i) {
        numbers[i] = i+1;
    }

    do {
        vector < int > shifts(n);
        for (int i = 0; i < n; ++i) {
            shifts[i] = i;
        }

        do {
            int trace = 0;
            for (int i = 0; i < n; ++i) {
//                cout << "Trace " << i << ", num = " << numbers[shifts[i]] << "\n";
                trace += numbers[(i + shifts[i]) % n];
            }

            /*
            cout << "Numbers: " ;
            for (auto& number : numbers) {
                cout << number << " ";
            }
            cout << ", Shifts: ";
            for (auto& shift : shifts) {
                cout << shift << " ";
            }
            cout << ", Trace = " << trace << "\n";
            //*/

            if (results[n].count(trace) == 0) {
                results[n][trace].first_row = numbers;
                results[n][trace].shifts    = shifts;
            }
        } while (next_permutation(shifts.begin(), shifts.end()));
    } while (next_permutation(numbers.begin(), numbers.end()));
}

void print(const Matrix &m, int tr = 0) {
    int n = m.first_row.size();

    vector < set < int > > columns(n);
    vector < set < int > > rows(n);
    int trace = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            auto number = m.first_row[(j + m.shifts[i]) % n];
            cout << number << " ";

            if (CHECK) {
                rows[i].insert(number);
                columns[j].insert(number);
                if (i == j)
                    trace += number;
            }
        }
        cout << "\n";
    }

    if (CHECK) {
        for (int i = 0; i < n; ++i) {
            if (columns[i].size() != n || rows[i].size() != n || trace != tr) {
                cout << "KWA!\n";
                return;
            }
        }
    }
}

int main() {
    freopen("input.txt", "r+", stdin);
    freopen("output.txt", "w+", stdout);

    int t;
    cin >> t;
    for (int tst = 1; tst <= t; ++tst) {
        int n, k;
        cin >> n >> k;

        if (results.count(n) == 0) {
            precalc(n);
        }

        if (results[n].count(k) > 0) {
            cout << "Case #" << tst << ": POSSIBLE\n";
            print(results[n][k], k);
        } else {
            cout << "Case #" << tst << ": IMPOSSIBLE\n";
        }
    }
    return 0;
}
