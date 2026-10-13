#include<vector>
using namespace std;
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n);
        vector<int> rightSum(n);
        vector<int> answer(n);
        int prefix = 0;
        int suffix = 0;

        for(int i=0;i<n;i++){
            if(i > 0){
                prefix +=nums[i-1];
                leftSum[i] = prefix;
            }
        }
        for(int i=n - 1;i >= 0;i--){
            if(i < n - 1){
                suffix +=nums[i+1];
                rightSum[i] = suffix;
            }
        }
        for(int i=0;i<n;i++){
            answer[i] = abs(leftSum[i] - rightSum[i]);
        }
        return answer;
    }
};