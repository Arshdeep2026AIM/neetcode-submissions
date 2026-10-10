class Solution {
public:
    int climbStairs(int n) {
        int first = 2;
        int second = 1;
        int res = (n > 2) ? 0 : (n == 2) ? first : second;
        for (int i = 2; i < n; i++) {
            res = first + second;
            second = first;
            first = res;
        }
        return res;
    }
};
