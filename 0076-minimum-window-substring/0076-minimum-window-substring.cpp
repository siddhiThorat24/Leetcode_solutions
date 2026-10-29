
class Solution {
public:
    string minWindow(string s, string t) {
        int need[128] = {0};

        for (char c : t) {
            need[(unsigned char)c]++;
        }

        int left = 0;
        int missing = t.size();
        int start = 0;
        int minLen = INT_MAX;

        for (int right = 0; right < s.size(); right++) {
            unsigned char c = s[right];

            if (need[c] > 0) {
                missing--;
            }
            need[c]--;

            while (missing == 0) {
                int len = right - left + 1;

                if (len < minLen) {
                    minLen = len;
                    start = left;
                }

                unsigned char out = s[left];
                need[out]++;

                if (need[out] > 0) {
                    missing++;
                }

                left++;
            }
        }

        if (minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};
