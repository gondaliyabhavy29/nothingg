#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void addFactors(int d, int delta, int& c2, int& c3, int& c5, int& c7) {
        if (d == 0) return;
        while (d % 2 == 0) { c2 += delta; d /= 2; }
        while (d % 3 == 0) { c3 += delta; d /= 3; }
        while (d % 5 == 0) { c5 += delta; d /= 5; }
        while (d % 7 == 0) { c7 += delta; d /= 7; }
    }

    int midi(int c2, int c3, int c5, int c7) {
        c2 = max(0, c2); c3 = max(0, c3);
        c5 = max(0, c5); c7 = max(0, c7);

        int count = c7 + c5 + (c3 / 2) + (c2 / 3);
        int r2 = c2 % 3;
        int r3 = c3 % 2;

        if (r2 == 2 && r3 == 1) count += 2;      // Needs '2' and '6' (product 12)
        else if (r2 > 0 || r3 > 0) count += 1;  // Fits in 1 digit ('2', '3', '4', or '6')

        return count;
    }

    string buildSuffix(int len, int c2, int c3, int c5, int c7) {
        c2 = max(0, c2); c3 = max(0, c3);
        c5 = max(0, c5); c7 = max(0, c7);

        string digits = "";
        for (int i = 0; i < c7; ++i) digits += '7';
        for (int i = 0; i < c5; ++i) digits += '5';
        for (int i = 0; i < c3 / 2; ++i) digits += '9';
        c3 %= 2;
        for (int i = 0; i < c2 / 3; ++i) digits += '8';
        c2 %= 3;

        if (c2 == 2 && c3 == 1) {
            digits += "26";
        } else if (c2 == 2) {
            digits += '4';
        } else if (c2 == 1 && c3 == 1) {
            digits += '6';
        } else if (c2 == 1) {
            digits += '2';
        } else if (c3 == 1) {
            digits += '3';
        }

        sort(digits.begin(), digits.end());
        string prefix(len - digits.length(), '1');
        return prefix + digits;
    }

    string smallestNumber(string num, long long t) {
        int c2 = 0, c3 = 0, c5 = 0, c7 = 0;
        
        long long temp = t;
        while (temp % 2 == 0) { temp /= 2; c2++; }
        while (temp % 3 == 0) { temp /= 3; c3++; }
        while (temp % 5 == 0) { temp /= 5; c5++; }
        while (temp % 7 == 0) { temp /= 7; c7++; }

        if (temp > 1) {
            return "-1";
        }
        
        int n = num.length();

        bool zeroFree = true;
        int cur2 = c2, cur3 = c3, cur5 = c5, cur7 = c7;
        for (char ch : num) {
            if (ch == '0') { zeroFree = false; break; }
            addFactors(ch - '0', -1, cur2, cur3, cur5, cur7);
        }
        if (zeroFree && cur2 <= 0 && cur3 <= 0 && cur5 <= 0 && cur7 <= 0) {
            return num;
        }

        vector<int> p2(n + 1, 0), p3(n + 1, 0), p5(n + 1, 0), p7(n + 1, 0);
        int firstZero = n;
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0') {
                firstZero = i;
                break;
            }
            p2[i + 1] = p2[i]; p3[i + 1] = p3[i];
            p5[i + 1] = p5[i]; p7[i + 1] = p7[i];
            addFactors(num[i] - '0', 1, p2[i + 1], p3[i + 1], p5[i + 1], p7[i + 1]);
        }

        for (int i = min(n - 1, firstZero); i >= 0; --i) {
            for (int d = num[i] - '0' + 1; d <= 9; ++d) {
                int r2 = c2 - p2[i], r3 = c3 - p3[i], r5 = c5 - p5[i], r7 = c7 - p7[i];
                addFactors(d, -1, r2, r3, r5, r7);

                int remLen = n - 1 - i;
                if (midi(r2, r3, r5, r7) <= remLen) {
                    string res = num.substr(0, i);
                    res += to_string(d);
                    res += buildSuffix(remLen, r2, r3, r5, r7);
                    return res;
                }
            }
        }

        int targetLen = max(n + 1, midi(c2, c3, c5, c7));
        return buildSuffix(targetLen, c2, c3, c5, c7);
    }
};