class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
      //if single element then return true
        if(n==1)
            return true;
        int reachable=0;  // stores the maximum reachable index
        for(int i=0;i<n;i++)
        {
          //if  present index is greater the max possible reachable index return false otherwise update the maximum possible reachable distance  
          if(i>reachable)
                return false;
            reachable=max(reachable,nums[i] + i);
        }
        return true;   
    }
};
