class Solution {
public:
  /*
  same as find duplicates 
  make all indexes negative at the end if any index remains positive push that index into the solution
  
  */
  vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int idx=abs(nums[i])-1;
            if(nums[idx]>0)
                nums[idx]*=-1;
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
                res.push_back(i+1);
        }
        return res;
    }
};
