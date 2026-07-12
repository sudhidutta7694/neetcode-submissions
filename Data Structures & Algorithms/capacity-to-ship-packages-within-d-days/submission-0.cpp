class Solution {
private:
    int calculateDays(vector<int>& weights, int cap) {
        int days = 1;
        int currentLoad = 0;

        for (int w : weights) {
            if (currentLoad + w > cap) {
                days++;
                currentLoad = 0;
            }
            currentLoad += w;
        }

        return days;
    }

public:
    int shipWithinDays(vector<int>& nums, int days) {
        if (nums.size() == 0) {
            return 0;
        }

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low)/2;

            if (calculateDays(nums, mid) <= days) {
                ans = mid;
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }

        return ans;
    }
};