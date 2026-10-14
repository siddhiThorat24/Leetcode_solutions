#include<unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> umap;
        int required = 0;
        for(int i=0;i<numbers.size();i++){
            required = target - numbers[i];
            if(umap.find(required) != umap.end()){
                return {umap[required] + 1,i+1};
            }
            umap[numbers[i]] = i;
        }
        return {};
    }
};