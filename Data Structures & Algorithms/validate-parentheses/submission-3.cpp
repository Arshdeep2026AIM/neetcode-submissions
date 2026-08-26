#include <stack>
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto character : s) {
            if (character == ')' || character == '}' || character == ']')
                {
                    if (st.empty()) return false;
                    char check = st.top();
                    st.pop();

                    if (character == ')') if (check != '(') return false;
                    if (character == '}') if (check != '{') return false;
                    if (character == ']') if (check != '[') return false;
                }
            else if (character == '(' || character == '{' || character == '[') st.push(character);
            else return false;
        }

        if (!st.empty()) return false;
        return true;
    }
};
