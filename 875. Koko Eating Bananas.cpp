class Solution {
public:
    bool canEat(vector<int>& piles, int h,int mid)
    {
        int hours=0;
        for(int i=0;i<piles.size();i++)
        {
            hours+=piles[i]/mid + (piles[i]%mid !=0);
            if(hours>h)
                return false;
        }
        if(hours<=h)
            return true;
        else
            return false;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int res=-1,start=1,end=*max_element(piles.begin(),piles.end());
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(canEat(piles,h,mid))
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
