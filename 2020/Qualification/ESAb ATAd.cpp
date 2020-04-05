#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;

const bool DEBUG_OUT = false;
const bool INPUT_FROM_TST = false;

int ESAb_ATAd() {
    if (INPUT_FROM_TST) {
        freopen("input.txt", "r+", stdin);
    }

    int t, b;
    cin >> t >> b;
    vector < int > bits(b, 2);
    for (int tst = 1; tst <= t; ++tst) {
        if (b <= 10) {
            for (auto& bit: bits) {
                bit = 0;
            }

            for (int i = 0; i < b; ++i) {
                cout << i+1 << "\n";
                string s;
                cin >> s;
                if (s == "N") {
                    return 0;
                }
                bits[i] = atoi(s.c_str());
            }

            for (auto& bit: bits) {
                cout << bit;
            }
            cout << "\n";

            string result;
            cin >> result;

            if (result == "Y") {
                continue;
            } else {
                return 0;
            }
        } else {
            int unknown_bits = b;
            set < int > matched_pair;
            set < int > mismatched_pair;
            while (unknown_bits > 0) {
                if (unknown_bits == b) {
                    for (int i = 0; i < 5; ++i) {
                        int pos1 = i;
                        int pos2 = b - 1 - pos1;
                        cout << pos1 + 1 << "\n";
                        cin >> bits[pos1];
                        cout << pos2 + 1 << "\n";
                        cin >> bits[pos2];

                        if (bits[pos1] != bits[pos2]) {
                            mismatched_pair.insert(pos1);
                        } else {
                            matched_pair.insert(pos1);
                        }

                        unknown_bits -= 2;
                    }
                } else {
                    if (DEBUG_OUT) {
                        for (int i = 0; i < b; ++i) {
                            cout << bits[i];
                        }
                        cout << "\n";
                    }

                    if (mismatched_pair.size() == 0 || matched_pair.size() == 0) {
                        int bit1;
                        cout << "1\n";
                        cin >> bit1;
                        int bitb;
                        cout << b << "\n";
                        cin >> bitb;

                        if (bit1 != bits[0]) {
                            for (auto& bit : bits) {
                                if (bit == 0) {
                                    bit = 1;
                                } else if (bit == 1) {
                                    bit = 0;
                                }
                            }
                        }
                        if (DEBUG_OUT) {
                            for (int i = 0; i < b; ++i) {
                                cout << bits[i];
                            }
                            cout << "\n";
                        }

                        for (int i = 0; i < 4; ++i) {
                            int pos1 = matched_pair.size() + mismatched_pair.size();
                            cout << pos1 + 1 << "\n";
                            cin >> bits[pos1];
                            int pos2 = b - pos1 - 1;
                            cout << pos2 + 1 << "\n";
                            cin >> bits[pos2];

                            if (bits[pos1] != bits[pos2]) {
                                mismatched_pair.insert(pos1);
                            } else {
                                matched_pair.insert(pos1);
                            }

                            unknown_bits -= 2;
                            if (unknown_bits <= 0) {
                                break;
                            }
                        }
                    } else {
                        int position_matched    = *   matched_pair.begin();
                        int position_mismatched = *mismatched_pair.begin();

                        int bit_matched;
                        cout << position_matched + 1 << "\n";
                        cin >> bit_matched;
                        int bit_mismatched;
                        cout << position_mismatched + 1 << "\n";
                        cin >> bit_mismatched;

                        bool swap_op = false;
                        if (bit_matched != bits[position_matched]) {
                            swap_op = true;
                        }

                        bool reverse_op = false;
                        if (!swap_op && bit_mismatched != bits[position_mismatched]) {
                            reverse_op = true;
                        } else if (swap_op && bit_mismatched == bits[position_mismatched]) {
                            reverse_op = true;
                        }

                        if (reverse_op) {
                            reverse(bits.begin(), bits.end());
                        }
                        if (swap_op) {
                            for (auto& bit : bits) {
                                if (bit == 0) {
                                    bit = 1;
                                } else if (bit == 1) {
                                    bit = 0;
                                }
                            }
                        }

                        if (DEBUG_OUT) {
                            for (int i = 0; i < b; ++i) {
                                cout << bits[i];
                            }
                            cout << "\n";
                        }

                        for (int i = 0; i < 4; ++i) {
                            int pos1 = matched_pair.size() + mismatched_pair.size();
                            cout << pos1 + 1 << "\n";
                            cin >> bits[pos1];
                            int pos2 = b - pos1 - 1;
                            cout << pos2 + 1 << "\n";
                            cin >> bits[pos2];

                            if (bits[pos1] != bits[pos2]) {
                                mismatched_pair.insert(pos1);
                            } else {
                                matched_pair.insert(pos1);
                            }

                            unknown_bits -= 2;
                            if (unknown_bits <= 0) {
                                break;
                            }
                        }
                    }
                }
            }

            for (auto& bit: bits) {
                cout << bit;
            }
            cout << "\n";

            string result;
            cin >> result;

            if (!INPUT_FROM_TST) {
                if (result == "Y") {
                    continue;
                } else {
                    return 0;
                }
            } else {
                for (int q = 0; q < result.length(); ++q) {
                    if (result[q]-'0' != bits[q]) {
                        cout << "NO! at test " << tst << "\n";
                        return 0;
                    }
                }
                cout << "YES! at test " << tst << "\n";
                continue;
            }
        }
    }

    return 0;
}
