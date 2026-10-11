class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            count += helper(s, i, i);
            count += helper(s, i, i+1);   
        }
        return count;
    }

    int helper(string& s, int idx1, int idx2) {
        int l = idx1, r = idx2;
        int temp = 0;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            temp++;
            l--;
            r++;
        }
        return temp;
    }
};
