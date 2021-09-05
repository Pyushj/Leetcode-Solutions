class Solution {
public:
  //the array can contain duplicates so binary search cannot be used
    char nextGreatestLetter(vector<char>& arr, char target) {
        
        char ch;
        int freq[26]={};
        for(int i=0;i<arr.size();i++)
        {
            freq[arr[i]-'a']++;
        }
        for(int i=target-'a'+1;i<26;i++)
        {
            if(freq[i]!=0)
            {
                ch=(char)(i+'a');
                return ch;
            }
        }
        for(int i=0;i<=target-'a';i++)
        {
            if(freq[i]!=0)
            {
                ch=(char)(i+'a');
                return ch;
            }
        }
        return ch;
        
        
    }
};
