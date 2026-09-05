class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int entry: nums) {
            if (seen.find(entry) == seen.end()) seen.insert(entry);
            else return true;
        }
        return false;
    }
};