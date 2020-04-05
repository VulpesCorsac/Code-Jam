#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

int Nesting_Depth() {
    int t;
    cin >> t;
    for (int tst = 1; tst <= t; ++tst) {
        string s, ans;
        cin >> s;

        int opened = 0;
        for (size_t i = 0; i < s.length(); ++i) {
            while (s[i] - '0' > opened) {
                ++opened;
                ans += '(';
            }
            while (s[i] - '0' < opened) {
                --opened;
                ans += ')';
            }
            ans += s[i];
        }
        while (opened) {
            --opened;
            ans += ')';
        }

        cout << "Case #" << tst << ": " << ans << "\n";
    }

    return 0;
}
