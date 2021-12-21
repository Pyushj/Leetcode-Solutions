class Solution {
public:
    
    bool isValid(vector<int>& nums,int n,int m,int key)
    {
        int stud=1,sum=0;
        for(auto x: nums)
        {
            sum+=x;
            if(sum>key)
            {
                sum=x;
                stud++;
            }
            if(stud>m)
                return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        
        int n=nums.size(),mx=-1,sum=0;
        if(n==m)
            return *max_element(nums.begin(),nums.end());
        for(auto x: nums)
        {
            sum+=x;
            mx=max(mx,x);
        }
        int start=mx,end=sum,res=-1;
        while(start<=end)
        {
            int mid=start + (end-start)/2;
            if(isValid(nums,n,m,mid))
            {
                res=mid;
                end=mid-1;
            }
            else
                start=mid+1;     
        }
        return res;
    }
};
