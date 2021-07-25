/*
##############################
Celebrity Problem GeeksforGeeks
https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
##############################
*/ 



// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here
        stack<int> s;
        int x,y;
        int t = n;
        
        // push row index in stack
        while(t){
            s.push(--t);
        } 

        // continue till stack become empty
        while(s.size()){
            // pop two row index
            x = s.top(); 
            s.pop();
            if(!s.size()){
                // if x was the last element in stack than check is it actual celebrity or not
                for(int i=0;i<n;i++){
                    if(i != x){
                        if(M[i][x] == 0) // if any ith person not Know X than X is not celebrity
                            return -1;
                    }
                }
                return x;
            }
                
            y = s.top();
            s.pop();
            if(M[x][y]){ // if x know y mean M[x][y] = 1 => x can not be celebrity as celebrity does not know anyone
                s.push(y); //y may be celebrity so push again in stack
            }
            else{ // if x does not know y mean M[x][y] = 0 => Y can not be celebrity as everyone know celebrity.
                s.push(x); // x may be celebrity so push again in stack
            }
        }
        return -1;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends