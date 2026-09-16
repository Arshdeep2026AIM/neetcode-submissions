class Solution {
public:
    /*int findMin(vector<int> &nums) {
        int size = nums.size();
        if (size == 2) return min(nums[0], nums[1]);
        int start = 0, end = size - 1;
        int min = nums[0];
        if (nums[size - 1] >= min) return min;
        while (start <= end) {
            int mid = (start + end)/2;
            if (nums[mid] > min) start = mid + 1;
            else if (nums[mid] < min) {
                min = nums[mid];
                end = mid - 1;
            }
        }
        return min;
    }*/

    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        int min = nums[l];
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] < min) {
                min = nums[mid];
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return min;
    }
};
