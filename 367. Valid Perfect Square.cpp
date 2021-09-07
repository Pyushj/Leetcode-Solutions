class Solution {
public:
    bool isPerfectSquare(int num) {
        int l=1,h=num;
        while(l<=h)
        {
            int mid= l+(h-l)/2;
            if( mid<=INT_MAX/mid && mid*mid==num)
                return true;
            else if(mid<=INT_MAX/mid && mid*mid <num)
                l=mid+1;
            else
                h=mid-1;
        }
        return false;
    }
};
