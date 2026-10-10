class Solution {
public:
    int helper(vector<int>& num) {
        int rob1 = 0, rob2 = 0;
        int res;
        for (int i = 0; i < num.size(); i++) {
            res = max(rob1 + num[i], rob2);
            rob1 = rob2;
            rob2 = res;
        }
        return res;
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> sub1(nums.begin() + 1, nums.end());
        vector<int> sub2(nums.begin(), nums.end() - 1);
        return(max(helper(sub1), helper(sub2)));
    }
};
