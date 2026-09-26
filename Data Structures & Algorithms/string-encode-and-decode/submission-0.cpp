class Solution {
public:

    string encode(vector<string>& strs) {
        string sym = "^#^";
        string res = "";
        for (string entry: strs) {
            res += entry;
            res += sym;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<int> idx;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '^') {
                if (i + 1 < s.size() && s[i + 1] == '#') {
                    if (i + 2 < s.size() && s[i + 2] == '^') idx.push_back(i);
                }
            }
        }
        vector<string> res = {};
        int l = 0;
        if (idx.size() == 0) return res;
        for (int entry: idx) {
            string temp = "";
            while (l < entry) {
                temp += s[l];
                l++;
            }
            res.push_back(temp);
            l = entry + 3;
        }
        if (l < s.size()) {
        string temp = "";
        while (l < s.size()) {
            temp += s[l];
            l++;
        }
        res.push_back(temp);
        }
        return res;
    }
};
