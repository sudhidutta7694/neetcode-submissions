class Solution {
public:
    //find minimum in rotated sorted array
    int findMin(vector<int> &nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        int low = 0;
        int high = n-1;

        int ans = INT_MAX;

        while (low <= high) {

            //entire range sorted
            if (nums[low] <= nums[high]) {
                ans = min(ans, nums[low]);
                break;
            }

            int mid = low + (high - low)/2;

            //find which half is sorted
            if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid + 1;
            } else { // (nums[mid] <= nums[high])
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }

        return ans;
    } 
};
