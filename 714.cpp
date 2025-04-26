class Solution {
    public:
        int maxProfit(vector<int>& prices, int fee) {
            int hold = -prices[0];  // Start with buying the first stock
            int cash = 0;           // No stock, zero profit
    
            for(int i = 1; i < prices.size(); i++) {
                hold = max(hold, cash - prices[i]);           // Buy or keep holding
                cash = max(cash, hold + prices[i] - fee);     // Sell or do nothing
            }
    
            return cash;
        }
    };
    