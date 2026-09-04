#include <cctype>
#include <vector>

class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> ltor, rtol;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            if (isalnum(s[i])) ltor.push_back(static_cast<char>(tolower(static_cast<unsigned char>(s[i]))));
            if (isalnum(s[len - i - 1])) rtol.push_back(static_cast<char>(tolower(static_cast<unsigned char>(s[len - i - 1]))));
        }

        if (ltor == rtol) return true;
        return false;
    }

};
