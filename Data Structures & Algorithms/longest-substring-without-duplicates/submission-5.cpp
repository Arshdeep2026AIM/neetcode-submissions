class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l = 0, res = 0;

        for (int r = 0; r < s.size(); r++) {
            if (mp.find(s[r]) != mp.end()) {
                l = max(mp[s[r]] + 1, l);
            }
            mp[s[r]] = r;
            res = max(res, r - l + 1);
        }
        return res;


        unordered_map<char, int> dynamic;
        int longest = 0;
        int idx = 0, startIdx = 0;
        for (char entry: s) {
            auto it = dynamic.find(entry);
            if (it == dynamic.end()) {
                dynamic.insert({entry, idx});
                if ((idx - startIdx + 1) > longest) longest = idx - startIdx + 1;
            }
            else {
                while(startIdx <= it->second) startIdx++;
                dynamic[entry] = idx;
                if ((idx - startIdx + 1) > longest) longest = idx - startIdx + 1;
            }
            idx++;
        }
        return longest;
    }
};  
