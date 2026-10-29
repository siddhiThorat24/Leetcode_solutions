
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256] = {0};
        int left = 0, ans = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[(unsigned char)s[right]]++;

            while (freq[(unsigned char)s[right]] > 1) {
                freq[(unsigned char)s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
