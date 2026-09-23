class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int max = 0;
        while (l < r) {
            if ((r - l) * min(heights[l], heights[r]) > max) max = (r - l) * min(heights[l], heights[r]);
            if (heights[l] > heights[r]) r--;
            else l++; 
        }
        return max;
    }
};
