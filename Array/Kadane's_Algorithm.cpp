/*
##############################
Largest Sum of contiguous subarry Problem gfg 
https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
##############################
*/ 

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n){ // T : O(n)
        
        // Your code here
        int max_so_far = INT_MIN;
        int max_end = 0;
        for(int i=0;i<n;i++){
            max_end = max_end + arr[i];
            if(max_so_far < max_end){
                max_so_far = max_end;
            }
            if(max_end < 0)
                max_end = 0;
        }
        return max_so_far;
    }
};

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
