#include<unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;

        for(int i=0;i<nums.size();i++){
            int required = target-nums[i];
            if(umap.find(required) != umap.end()){
                return {umap[required],i};
            }
            umap[nums[i]] = i;
        }
        return {};
    }
};