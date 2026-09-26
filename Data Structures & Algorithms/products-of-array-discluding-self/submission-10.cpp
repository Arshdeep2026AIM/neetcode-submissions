class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total = 1;
        int total2 = 1;
        vector<int> zeroIdx;
        vector<int> outputs(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) total = total * nums[i];
            else zeroIdx.push_back(i);
        }
        if (zeroIdx.size() > 1) return outputs;
        else if (zeroIdx.size() == 1) outputs[zeroIdx[0]] = total;
        else {
            for (int i = 0; i < nums.size(); i++) {
                outputs[i] = total / nums[i];
            }
        }
        return outputs;
    }
};
