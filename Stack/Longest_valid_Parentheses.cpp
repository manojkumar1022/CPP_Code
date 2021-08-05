/*
##############################
Longest Valid Parentheses leetcode
https://leetcode.com/problems/longest-valid-parentheses/
````````````````````````````````````````````````````````
Valid Substring gfg
https://practice.geeksforgeeks.org/problems/valid-substring0624/1
`````````````````````````````````````````````````````````````````
##############################
*/ 
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

//`````````````````````````````````````````````````` //
// Aproach #1 // Time : O(N) // Space : O (N) // 2 - Stack   //
//.................................................. //

    int findMaxLen(string s) {
        // code here
        int len = 0;
        stack<char> st;
        stack<int> idx;
        idx.push(-1);
        
        for(int i = 0;i<s.length();i++)
        {
            if(s[i] == '(')
            {
                st.push('(');
                idx.push(i);
            }
            else if(s[i] == ')')
            {
                if(st.size())
                {
                    idx.pop();
                    st.pop();
                    len = max(len,i - idx.top());
                }
                else{
                    idx.push(i);
                }
            }
        }
        return len;
    }


//`````````````````````````````````````````````````` //
// Aproach #2 // Time : O(N) // Space : O (N) // 1 - Stack   //
//.................................................. //


    int findMaxLen1(string s) {
        // code here
        int len = 0;
        stack<char> st;
        idx.push(-1);
        
        for(int i = 0;i<s.length();i++)
        {
            if(s[i] == '(')
                idx.push(i);
            else if(s[i] == ')')
            {
                idx.pop();
                if(idx.size())
                {
                    len = max(len,i - idx.top());
                }
                else{
                    idx.push(i);
                }
            }
        }
        return len;
    }



//`````````````````````````````````````````````````` //
// Aproach #3 // Time : O(N) // Space : O (1)        //
//.................................................. //
    int maxLength(string S){
        // code here
        int len=0;
        int left = 0,right=0;

        for(int i=0;i<S.length();i++){
            if(S[i] == '('){
                left++;
            }
            else if(S[i] == ')'){
                right++;
            }
            if(right == left)
                len = max(len,2*right);
            else if(left > right)
                right = left = 0;
        }
        
        right = left =0;
        for(int i=S.length() - 1;i>=0;i--)
        {
            if(S[i] == '('){
                left++;
            }
            else if(S[i] == ')'){
                right++;
            }
            if(right == left)
                len = max(len,2*right);
            else if(left < right)
                right = left = 0;
        }

        return len;
    }

    
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}  
