class Solution {
public:
    //9
    //1 2 3 4 5 6 7 8 9

    int mySqrt(int x) {
        if (x == 0) return 0;

        int low = 1, high = x;
        int ans = 1;

        while (low <= high) {
            int mid = low + (high - low)/2;

            if (mid <= x / mid) //same as mid * mid <= x, used like this to prevent overflow
            {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};