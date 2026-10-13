class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int leftSum = 0;
        int total = 0;
        int rightSum = 0;
        for(int num:nums){
            total += num;
        }
        for(int i=0;i<nums.size();i++){
            rightSum = total - leftSum - nums[i];
            if(leftSum == rightSum){
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};