class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int left = 0;
        int zeros = 0;
        int maxLength = 0;

        for (int right = 0; right < nums.size(); right++) {

            // Add current element
            if (nums[right] == 0) {
                zeros++;
            }

            // Window is invalid
            while (zeros > k) {

                if (nums[left] == 0) {
                    zeros--;
                }

                left++;
            }

            // Window is valid
            maxLength = max(
                maxLength,
                right - left + 1
            );
        }

        return maxLength;
    }
};