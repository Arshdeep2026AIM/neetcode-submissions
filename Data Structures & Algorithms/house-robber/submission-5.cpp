class Solution {
public:
    int rob(vector<int>& nums) {
        int first = 0, second = 0;
        int res;
        for (int i = 0; i < nums.size(); i++) {
            res = max(first + nums[i], second);
            first = second;
            second = res;
        }
        return res;
    }
};
