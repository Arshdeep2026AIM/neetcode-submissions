class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> index;
        vector<int> result;
        int idx1, idx2;
        for (int i = 0; i < nums.size(); i++) {
            if (index.find(target - nums[i]) == index.end()) {
                index.insert({nums[i], i});
            }
            else {
                int temp = index.find(target - nums[i])->second;
                idx1 = (i < temp) ? i : temp;
                idx2 = (idx1 == i) ? temp : i;
                break;
            }
        }
        result.push_back(idx1);
        result.push_back(idx2);
        return result;
    }
};
