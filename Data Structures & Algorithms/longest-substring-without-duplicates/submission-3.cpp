class Solution {
public:
    int lengthOfLongestSubstring(string s) {
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
