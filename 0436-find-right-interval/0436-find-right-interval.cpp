class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {

        int n = intervals.size();

        vector<pair<int,int>> starts;

        for(int i = 0; i < n; i++) {
            starts.push_back({intervals[i][0], i});
        }

        sort(starts.begin(), starts.end());

        vector<int> ans;

        for(int i = 0; i < n; i++) {

            int target = intervals[i][1];

            int low = 0;
            int high = n;

            while(low < high) {

                int mid = low + (high - low) / 2;

                if(starts[mid].first < target)
                    low = mid + 1;
                else
                    high = mid;
            }

            if(low == n)
                ans.push_back(-1);
            else
                ans.push_back(starts[low].second);
        }

        return ans;
    }
};