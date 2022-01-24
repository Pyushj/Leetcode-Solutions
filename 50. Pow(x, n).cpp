class Solution {
public:
    double power(double x,int n)
    {
        if(n==0)
            return 1;
        double temp=power(x,n/2);
        
        if(n%2==0)
            return temp*temp;
        else
            return temp*temp*x;
    }
    double myPow(double x, int n) {
        
        double res;
        if(n>0)
            res=power(x,n);
        else
        {
            int num=abs(n);
            res=(1/power(x,num));
        }
        return res;
        
    }
};
