class Solution {
public:
    bool isAnagram(string s, string t) {
        int len1 = s.size();
        if (len1 != t.size()) return false;

        vector<int> count(26, 0);
        for (int i = 0; i < len1; i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }        

        for (int val: count) {
            if (val != 0) return false;
        }
        return true;
    }
};
