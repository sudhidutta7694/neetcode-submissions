class Solution {
private:
    int countSplits(vector<int>& nums, int sum) {
        int splits = 1;
        int currEle = nums[0];

        for (int i=1; i<nums.size(); i++) {
            if (currEle + nums[i] <= sum) {
                currEle += nums[i];
            } else {
                splits++;
                currEle = nums[i];
            }
        }

        return splits;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        if (n < k) return -1;
        
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high) {
            int mid = low + (high - low)/2;

            int splitCnt = countSplits(nums, mid);

            if (splitCnt > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};