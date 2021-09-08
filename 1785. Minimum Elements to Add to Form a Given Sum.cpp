class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
      long long int sum=0;
        for(auto x:nums)
        {
            sum+=x;
        }
        long long int toAdd=abs(goal-sum);
        int count= toAdd/limit;
        toAdd= toAdd%limit;
        if(toAdd!=0)
            count++;
        return count;
        
    }
};
