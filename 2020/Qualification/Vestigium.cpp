#include <iostream>
#include <vector>
#include <set>

using namespace std;

int Vestigium() {
    int t;
    cin >> t;
    for (int tst = 0; tst < t; ++tst) {
        int n;
        cin >> n;
        int tr = 0, r = 0, c = 0;
        vector < vector < int > > arr(n, vector < int >(n, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> arr[i][j];
                if (i == j) {
                    tr += arr[i][j];
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            set < int > nums;

            for (int j = 0; j < n; ++j) {
                nums.insert(arr[i][j]);
            }

            if (nums.size() != n || *nums.rbegin() != n) {
                ++r;
            }
        }

        for (int j = 0; j < n; ++j) {
            set < int > nums;

            for (int i = 0; i < n; ++i) {
                nums.insert(arr[i][j]);
            }

            if (nums.size() != n || *nums.rbegin() != n) {
                ++c;
            }
        }

        cout << "Case #" << tst+1 << ": " << tr << " " << r << " " << c << "\n";
    }

    return 0;
}
