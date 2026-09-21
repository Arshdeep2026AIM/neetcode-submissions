class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int idx = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                idx = mid;
                break;
            }
            else if (nums[mid] > nums[l]) {
                if (target < nums[mid] && target >= nums[l]) r = mid - 1;
                else l = mid + 1;
            }
            else if (nums[mid] < nums[r]) {
                if (target > nums[mid] && target <= nums[r]) l = mid + 1;
                else r = mid - 1;
            }
            else {
                if (target == nums[r]) idx = r;
                break;
            }   
        }
        return idx;
    }
};
