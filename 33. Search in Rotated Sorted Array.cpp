class Solution {
public:
    int minIndex(vector<int>& nums,int n)
    {
        int start=0,end=n-1;
        if(nums[start]<nums[end])
            return start;
        while(start<=end)
        {
            int mid=start + (end-start)/2;
            int prev=(mid+n-1)%n;
            int next=(mid+1)%n;
            if(nums[mid]< nums[prev] && nums[mid] < nums[next])
                return mid;
            else if(nums[0] <=nums[mid])
                start=mid+1;
            else
                end=mid-1;
        }
        return -1;
        
    }
    int binSearch(vector<int>& nums, int target,int start,int end)
    {
        while(start<=end)
        {
            int mid= start +(end-start)/2;
            if(nums[mid]== target)
                return mid;
            else if(nums[mid] >target)
                end=mid-1;
            else
                start=mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==1)
        {
            return (nums[0]==target)? 0:-1;
        }
        int minIdx=minIndex(nums,n);  
        // if the target is smaller than the first element then search it int the second half
        if(minIdx==0 || target< nums[0])
        {
            return binSearch(nums,target,minIdx,n-1);
        }
        else
            return binSearch(nums,target,0,minIdx-1);  
    }
};
