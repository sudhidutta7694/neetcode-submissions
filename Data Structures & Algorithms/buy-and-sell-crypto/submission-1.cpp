class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        if (n <= 1) return 0;

        int left = 0, right = 1;
        int profitMax = 0;

        while (right < n) {
            int profit = prices[right] - prices[left];

            if (profit < 0) {
                left = right;
            } else {
                profitMax = max(profitMax, profit);
            }

            right++;
        }

        return profitMax;
    }
};
