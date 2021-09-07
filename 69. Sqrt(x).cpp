class Solution {
public:
    int mySqrt(int x) {
        
        if(x==0)
            return 0;
        int l=1,h=x;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(mid<=INT_MAX/mid && mid*mid==x)
                return mid;
            else if(mid<=INT_MAX/mid && mid*mid<x)
                l=mid+1;
            else
                h=mid-1;
        }
        return h;
        
        
    }
};
