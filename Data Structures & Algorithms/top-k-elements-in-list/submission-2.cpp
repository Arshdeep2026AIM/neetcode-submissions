class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            auto it = mp.find(nums[i]);
            if (it == mp.end()) mp.insert({nums[i], 0});
            mp[nums[i]]++;
        }
        vector<vector<int>> inter(nums.size() + 1);
        int max = 0;
        for (const auto& [num, freq] : mp) {
            inter[freq].push_back(num);
            if (freq > max) max = freq;
        }
        vector<int> result;
        while (k > 0 && max >= 0) {
            for (int entry : inter[max]) {
                result.push_back(entry);
                k--;
            }
            max--;
        }
        return result;
    }
};
