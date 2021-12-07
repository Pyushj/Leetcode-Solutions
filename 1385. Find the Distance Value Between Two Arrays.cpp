class Solution {
public:
    int closest(vector<int>& arr,int n,int key)
    {
        if(key<=arr[0])
            return arr[0];
        if(key>=arr[n-1])
            return arr[n-1];
        int start=0,end=n-1,diff=INT_MAX,res=-1;
        while(start<=end)
        {
            int mid=start + (end-start)/2;
            if(arr[mid]==key)
                return arr[mid];
            if(arr[mid] > key)
            {
                int newDiff=abs(arr[mid]-key);
                if(newDiff < diff)
                {
                    diff=newDiff;
                    res=arr[mid];
                }
                end=mid-1;
            }
            else
            {
                int newDiff=abs(arr[mid]-key);
                if(newDiff < diff)
                {
                    diff=newDiff;
                    res=arr[mid];
                }
                start=mid+1;  
            }
        }
        return res;
    }
    
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        
        sort(arr2.begin(),arr2.end());
        int n=arr2.size();
        int count=0;
        for(int i=0;i<arr1.size();i++)
        {
            int clos=closest(arr2,n,arr1[i]);
            if( (abs(clos-arr1[i])) > d)
                count++;
        }
        return count;    
    }
};
