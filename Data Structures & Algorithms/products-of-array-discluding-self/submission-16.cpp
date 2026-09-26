class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> outputs(nums.size());
        vector<int> prefixArr(nums.size()), suffixArr(nums.size());
        int running = 1;
        for (int i = 0; i < nums.size(); i++) {
            prefixArr[i] = running;
            running = running * nums[i];
        }
        running = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            suffixArr[i] = running;
            running = running * nums[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            outputs[i] = prefixArr[i] * suffixArr[i];
        }
        return outputs;
    }
};
