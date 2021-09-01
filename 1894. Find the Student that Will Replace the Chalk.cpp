class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
      
      /* find the sum of the array elements then find the rem of k%sum
        start iterating from 0th index and the moment rem is less than arr[i] return thr index i.
        */
        
      long long int sum=0,rem=0;
        int n=chalk.size();
        for(int i=0;i<n;i++)
        {
            sum+=chalk[i];
        }
        rem=(int)(k%sum);
        for(int i=0;i<n;i++)
        {
            if(rem<chalk[i])
                return i;
            rem-=chalk[i];
        }
        return (n-1);
    }
};
