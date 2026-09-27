class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp.insert({nums[i], i});
        }

        unordered_map<int, int> visited;
        int longest = 0;
        for (int i = 0; i < nums.size(); i++) {
            auto it = visited.find(nums[i]);
            if (it != mp.end()) continue;
            visited.insert({nums[i], 1});

            int temp = 1;
            auto it2 = mp.find(nums[i] - temp);
            while (it2 != mp.end()) {
                if (visited.find(it2->first) != visited.end()) {
                    visited[nums[i]] += visited[nums[i] - temp];
                    temp = visited[nums[i]];
                    break;
                }
                else {
                    temp++;
                    visited[nums[i]]++;
                    it2 = mp.find(nums[i] - temp);
                }
            }
            if (temp > longest) longest = temp;
        }
        return longest;
    }
};
