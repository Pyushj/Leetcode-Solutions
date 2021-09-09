class Solution {
public:
  // calculate prefix and suffix product then multiply the indivisual ones
    vector<int> productExceptSelf(vector<int>& arr) {
        
        int n=arr.size();
        vector<int> res(n,0);
        vector<int> pre(n,0);
        vector<int> suff(n,0);
        pre[0]=arr[0];
        suff[n-1]=arr[n-1];
        for(int i=1;i<n;i++)
        {
            pre[i]=arr[i]*pre[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            suff[i]=arr[i]*suff[i+1];
        }
        res[0]=suff[1];
        res[n-1]=pre[n-2];
        for(int i=1;i<n-1;i++)
        {
            res[i]=pre[i-1]*suff[i+1];
        }
        return res;
    }
};
