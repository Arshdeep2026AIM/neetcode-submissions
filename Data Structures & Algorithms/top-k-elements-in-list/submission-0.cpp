class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            auto it = mp.find(nums[i]);
            if (it == mp.end()) mp.insert({nums[i], 0});
            mp[nums[i]]++;
        }
        vector<int> res;
        for (int i = 0; i < k; i++) {
            int max = -1, maxElement = -1001;
            for (const auto &[num, freq] : mp) {
                if (freq > max) {
                    max = freq;
                    maxElement = num;
                }
            }
            mp.erase(maxElement);
            res.push_back(maxElement);
        }
        return res;
    }
};
