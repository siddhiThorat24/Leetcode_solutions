class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st;

        for(int num : nums) {
            st.insert(num);
        }

        int longest = 0;

        for(int num : st) {

            // Check whether num is the start
            if(st.find(num - 1) == st.end()) {

                int currentNum = num;
                int count = 1;

                // Count consecutive numbers
                while(st.find(currentNum + 1) != st.end()) {

                    currentNum++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};