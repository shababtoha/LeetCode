class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int isBuying = true;
        int lastStock = INT_MAX;
        int lastStockBought = -1;
        for(int i = 0 ; i<prices.size(); i++) {
            if(isBuying) {
                if(prices[i] > lastStock) {
                    lastStockBought = lastStock;
                    isBuying = false;
                }
            } else {
                if(prices[i] < lastStock) {
                    isBuying = true;
                    ans+= (lastStock - lastStockBought);
                }
            }
            lastStock = prices[i];
        }
        if(!isBuying && prices[prices.size()-1] > lastStockBought) {
            ans+= prices[prices.size()-1] - lastStockBought;
        }
        return ans;
    }
};