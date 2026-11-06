class Solution {
public:

    bool canSplit(vector<int>& nums,
                  int k, long long maxSum) {

        int parts = 1;
        long long currentSum = 0;

        for(int num : nums) {

            if(currentSum + num > maxSum) {
                parts++;
                currentSum = 0;
            }

            currentSum += num;
        }

        return parts <= k;
    }

    int splitArray(vector<int>& nums, int k) {

        long long low = *max_element(
            nums.begin(), nums.end()
        );

        long long high = accumulate(
            nums.begin(), nums.end(), 0LL
        );

        while(low < high) {

            long long mid = low + (high - low) / 2;

            if(canSplit(nums, k, mid))
                high = mid;
            else
                low = mid + 1;
        }

        return static_cast<int>(low);
    }
};