#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

struct Activity {
    int start  = 0;
    int finish = 0;
    int number = 0;
    char assigned = '_';
};

bool sortByStart(const Activity& lhs, const Activity& rhs) {
    return lhs.start < rhs.start;
}

bool sortByNumber(const Activity& lhs, const Activity& rhs) {
    return lhs.number < rhs.number;
}

int Parenting_Partnering_Returns() {
    int t;
    cin >> t;
    for (int tst = 1; tst <= t; ++tst) {
        int n;
        cin >> n;

        Activity lastCameron;
        Activity lastJamie;
        vector < Activity > activities(n);
        bool found = true;

        int num = 0;
        for (Activity& activity : activities) {
            cin >> activity.start >> activity.finish;
            activity.number = num++;
        }

        sort(activities.begin(), activities.end(), sortByStart);
        for (int i = 0; i < n; ++i) {
            if (activities[i].start >= lastCameron.finish) {
                lastCameron = activities[i];
                activities[i].assigned = 'C';
            } else if (activities[i].start >= lastJamie.finish) {
                lastJamie = activities[i];
                activities[i].assigned = 'J';
            } else {
                cout << "Case #" << tst << ": IMPOSSIBLE\n";
                found = false;
                break;
            }
        }

        if (found) {
            sort(activities.begin(), activities.end(), sortByNumber);
            cout << "Case #" << tst << ": ";
            for (Activity& activity : activities) {
                cout << activity.assigned;
            }
            cout << "\n";
        }
    }

    return 0;
}

