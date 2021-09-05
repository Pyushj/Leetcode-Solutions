class Solution {
public:
  /*
  make the first non 'a' character---> 'a'
  check for no. of a's if all elements are a make last index b
  if we have an odd length palindrome with one non a character [eg: aazaa making z->a will result into a palindrome so simply make last character 'b' "aazaa"-->"aazab"]
  */
    string breakPalindrome(string palin) {
        
        string res="";
        int n=palin.length();
        if(n==1)
            return res;
        
        int a=0;
        for(int i=0;i<n;i++)
        {
            if(palin[i]=='a')
            {
                a++;
            }
        }
        if(a==n || a==n-1)
        {
            palin[n-1]='b';
            return palin;
        }
        for(int i=0;i<n;i++)
        {
            if(palin[i]!='a')
            {
                palin[i]='a';
                return palin;
            }
        }
        return res; 
        
    }
};
