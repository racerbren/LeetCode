class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        vector<bool> result(candies.size(), false);
        int max = 0;

        for (int j = 0; j < candies.size(); j++)
        {
            if (candies[j] >= max)
                max = candies[j];
        }
        for (int i = 0; i < candies.size(); i++)
        {
            int temp = candies[i] + extraCandies;
            if (temp >= max)
                result[i] = true;
        } 
        return result;   
    }
};
