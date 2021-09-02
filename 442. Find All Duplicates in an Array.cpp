class Solution {
public:
  /*
      go to every index and make it negative if the value at the given index is already negative 
      it means it has already been visited so push it into the result array
  */
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            int idx=abs(nums[i])-1;
            if(nums[idx]<0)
                res.push_back(idx+1);
            else
                nums[idx]*=-1;
        }
        return res;
    }
};
