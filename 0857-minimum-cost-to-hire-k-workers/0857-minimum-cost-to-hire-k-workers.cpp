class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality,
                                vector<int>& wage,
                                int k) {

        int n = quality.size();

        vector<pair<double, int>> workers;

        for (int i = 0; i < n; i++) {

            double ratio =
                (double)wage[i] / quality[i];

            workers.push_back({ratio, quality[i]});
        }

        sort(workers.begin(), workers.end());

        priority_queue<int> pq;

        long long totalQuality = 0;
        double ans = DBL_MAX;

        for (auto [ratio, q] : workers) {

            pq.push(q);
            totalQuality += q;

            if (pq.size() > k) {
                totalQuality -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                ans = min(ans, ratio * totalQuality);
            }
        }

        return ans;
    }
};