class Solution {
public:
    int maximumGap(vector<int>& nums) {

        int n = nums.size();

        if (n < 2) return 0;

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        if (mn == mx) return 0;

        int bucketSize = max(1, (mx - mn) / (n - 1));
        int bucketCount = (mx - mn) / bucketSize + 1;

        vector<int> bucketMin(bucketCount, INT_MAX);
        vector<int> bucketMax(bucketCount, INT_MIN);

        for (int x : nums) {

            int index = (x - mn) / bucketSize;

            bucketMin[index] = min(bucketMin[index], x);
            bucketMax[index] = max(bucketMax[index], x);
        }

        int ans = 0;
        int previousMax = mn;

        for (int i = 0; i < bucketCount; i++) {

            if (bucketMin[i] == INT_MAX) {
                continue;
            }

            ans = max(ans, bucketMin[i] - previousMax);
            previousMax = bucketMax[i];
        }

        return ans;
    }
};