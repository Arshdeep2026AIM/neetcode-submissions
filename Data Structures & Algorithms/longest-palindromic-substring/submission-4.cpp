class Solution {
public:
    string longestPalindrome(string s) {
        int resIdx = 0, resLen = 0;

        for (int i = 0; i < s.size(); i++) {
            int l = i, r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if ((r - l + 1) > resLen) {
                    resLen = r - l + 1;
                    resIdx = l;
                }
                l--; 
                r++;
            }

            l = i, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if ((r - l + 1) > resLen) {
                    resLen = r - l + 1;
                    resIdx = l;
                }
                l--;
                r++;
            }
        }
        
        return s.substr(resIdx, resLen);


        /*
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < s.length(); i++) {
            auto it = mp.find(s[i]);
            if (it == mp.end()) mp[s[i]] = {i};
            else mp[s[i]].push_back(i);
        }
        int m = 0;
        int idx = 0, idx2 = 0;
        for (int i = 0; i < s.size(); i++) {
            char temp = s[i];
            auto it = mp.find(temp);
            if ((it->second).size() > 1) {
                for (int j = 0; j < (it->second).size(); j++) {
                    if (i == it->second[j]) continue;
                    int l = i, r = it->second[j];
                    int flag = 1, len = 2;
                    int idxstart = l, idxend = r;
                    l++, r--;
                    while (r > l) {
                        if (l == r) {
                            len++;
                            break;
                        }
                        if (s[l] != s[r]) {
                            flag = 0;
                            break;
                        }
                        l++, r--;
                    }
                    if (flag == 1) {
                        if (len > m) {
                            m = len;
                            idx = idxstart;
                            idx2 = idxend;
                        }
                    }
                }
            }
        }
        string res = "";
        for (int k = idx; k <= idx2; k++) {
            res += s[k];
        }
        return res;
        */
    }
};
