class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        int pricesSize = prices.size();
        if (pricesSize == 0) {
            return 0;
        }
        
        int buy = -prices[0];
        int sell = 0;
        
        for (int i = 1; i < pricesSize; i++) {
            sell = max(sell, buy + prices[i] - fee);
            buy = max(buy, sell - prices[i]);
        }
        return sell;
    }
};