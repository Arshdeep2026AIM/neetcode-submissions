class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int res = 0;

        int l = 0, maxf = 0;
        for (int i = 0; i < s.size(); i++) {
            count[s[i]]++;
            maxf = max(maxf, count[s[i]]);

            while (i - l + 1 - maxf > k) {
                count[s[l]]--;
                l++;
            }
            res = max(res, i - l + 1);
        }

        return res;
        /*


        int l = 0;
        int longest = 0;
        unordered_map<char, int> mp;
        int temp = 0, counter = 0;
        for (int i = 0; i < s.size(); i++) {
            auto it = mp.find(s[i]);
            if (it != mp.end()) {
                if (it->first == s[l]) it->second++;
                else if (counter < k) counter++;
                else {
                    if (it->second > longest) longest = it->second; 
                    while (s[l] != s[i]) l++;
                    if (l != i) counter = i - l + 1;
                }
            }
            else mp.insert({s[i], 1});
            if (s[i] != s[l]) counter++;
        }
        return longest;*/
    }
};
