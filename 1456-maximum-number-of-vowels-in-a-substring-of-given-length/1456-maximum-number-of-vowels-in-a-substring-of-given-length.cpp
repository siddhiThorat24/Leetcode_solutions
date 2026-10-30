class Solution {
public:

    bool isVowel(char ch) {
        return ch == 'a' || 
               ch == 'e' || 
               ch == 'i' || 
               ch == 'o' || 
               ch == 'u';
    }

    int maxVowels(string s, int k) {

        int count = 0;

        // First window
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                count++;
            }
        }

        int maxCount = count;

        // Slide the window
        for (int right = k; right < s.length(); right++) {

            // Add new character
            if (isVowel(s[right])) {
                count++;
            }

            // Remove old character
            if (isVowel(s[right - k])) {
                count--;
            }

            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};