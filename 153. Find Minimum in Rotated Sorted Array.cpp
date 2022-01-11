class Solution {
public:
    // minimum element always lies in unsorted array
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        int start=0,end=n-1;
        if(nums[start]< nums[end])
            return nums[start];
        while(start<=end)
        {
            int mid=start + (end-start)/2;
            int next=(mid+1)%n;
            int prev=(mid + n-1)%n;
            
            if(nums[mid] < nums[prev] && nums[mid] < nums[next])
                return nums[mid];
            // if left part is sorted search in right part
            if(nums[0] <= nums[mid])
                start=mid+1;
            else 
                end=mid-1;
        }
        return -1;
    }
};
