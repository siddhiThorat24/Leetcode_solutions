class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();

        if (m > n) return false;

        int need[26] = {0};
        int window[26] = {0};

        for (char c : s1) {
            need[c - 'a']++;
        }

        for (int i = 0; i < n; i++) {
            window[s2[i] - 'a']++;

            if (i >= m) {
                window[s2[i - m] - 'a']--;
            }

            if (window[0] == need[0]) {
                bool same = true;

                for (int j = 1; j < 26; j++) {
                    if (window[j] != need[j]) {
                        same = false;
                        break;
                    }
                }

                if (same) return true;
            }
        }

        return false;
    }
};
