
class Solution {
    int largestRectangle(vector<int>& h) {
        stack<int> st;
        int n = h.size();
        int ans = 0;

        for (int i = 0; i <= n; i++) {
            int curr = (i == n) ? 0 : h[i];

            while (!st.empty() &&
                   h[st.top()] > curr) {

                int height = h[st.top()];
                st.pop();

                int width = st.empty()
                    ? i
                    : i - st.top() - 1;

                ans = max(ans, height * width);
            }

            st.push(i);
        }

        return ans;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> heights(n, 0);
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }

            ans = max(ans, largestRectangle(heights));
        }

        return ans;
    }
};
