class Solution {
public:
    int countRangeSum(vector<int>& nums,
                      int lower, int upper) {

        vector<long long> prefix(nums.size() + 1, 0);

        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        return divide(prefix, 0, prefix.size(),
                      lower, upper);
    }

    int divide(vector<long long>& sums,
               int left, int right,
               int lower, int upper) {

        if (right - left <= 1) return 0;

        int mid = left + (right - left) / 2;

        long long count = 0;

        count += divide(sums, left, mid, lower, upper);
        count += divide(sums, mid, right, lower, upper);

        int j = mid, k = mid, t = mid;
        vector<long long> temp;

        for (int i = left; i < mid; i++) {

            while (k < right &&
                   sums[k] - sums[i] < lower) {
                k++;
            }

            while (j < right &&
                   sums[j] - sums[i] <= upper) {
                j++;
            }

            count += j - k;
        }

        int i = left;

        while (i < mid && t < right) {

            if (sums[i] <= sums[t]) {
                temp.push_back(sums[i++]);
            } else {
                temp.push_back(sums[t++]);
            }
        }

        while (i < mid) temp.push_back(sums[i++]);
        while (t < right) temp.push_back(sums[t++]);

        for (int x = 0; x < temp.size(); x++) {
            sums[left + x] = temp[x];
        }

        return (int)count;
    }
};