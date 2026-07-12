class Solution {
private:
    long long calculateTime(vector<int>& piles, int speed) {
        long long time = 0;

        for (int pile : piles) {
            time += (pile + speed - 1LL) / speed;
        }

        return time;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if (piles.size() == 0) {
            return 0;
        }

        int low = 1, high = *max_element(piles.begin(), piles.end());
        
        int k = high;

        while (low <= high) {
            int mid = low + (high - low)/2;

            if (calculateTime(piles, mid) <= h) {
                k = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return k;
    }
};