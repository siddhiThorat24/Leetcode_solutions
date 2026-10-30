class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        unordered_map<int, int> freq;

        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < fruits.size(); right++) {

            // Add current fruit
            freq[fruits[right]]++;

            // More than 2 types
            while (freq.size() > 2) {

                freq[fruits[left]]--;

                // Remove fruit completely
                if (freq[fruits[left]] == 0) {
                    freq.erase(fruits[left]);
                }

                left++;
            }

            // Current window is valid
            maxLength = max(
                maxLength,
                right - left + 1
            );
        }

        return maxLength;
    }
};