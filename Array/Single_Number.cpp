/*
##############################
Single Number leetcode
https://leetcode.com/problems/single-number/
https://leetcode.com/problems/single-number-ii/
https://leetcode.com/problems/single-number-iii/
````````````````````````````````````````````
Single Number gfg
https://practice.geeksforgeeks.org/problems/single-number1014/1
```````````````````````````````````````````````````````````````
##############################
*/ 

#include <bits/stdc++.h>
using namespace std;

//`````````````````````````````````````````````````` //
// Aproach #1 // Time : O(N*logN + N) // Space : O (1)    
// Using Sorting
//.................................................. //
int singleNumber1(vector<int> nums)
{
    int i=1,n = nums.size();
    int noOfTimeNoIsRepeating = 3; 
    if(n < noOfTimeNoIsRepeating)
        return nums[0];
    sort(nums.begin(),nums.end());
    if(nums[0] != nums[1])
        return nums[0];
    while(i<n)
    {
        if(nums[i-1] != nums[i])
            return nums[i-1];
        i += noOfTimeNoIsRepeating;
    }
    return nums[n-1];
}


//`````````````````````````````````````````````````` //
// Aproach #2 // Time : O(32*N) // Space : O (1)    
//  Using Counting SET BITS 
/*  (sorting method is better than this)
counting set bits (bestcase = worstcase = avgcase = (32*N))
sorting method (bestcase = O(N*logN), worstcase = O(N*logN + N))
Because LogN < 32 
*/  
//.................................................. //
int singleNumber2(vector<int> nums)
{
    unsigned int ans = 0, shift = 1;
    
    int count,i;
    int noOfTimeNoIsRepeating = 2; 
    int noOfTimeLoopContinue = 32; // is int take 4 byte so 4 * 8(1byte = 8bit) = 32 bit
    
    for(i=0; i<noOfTimeLoopContinue; i++){
        
        count = 0;
        for(auto ele:nums)
        {
            if(ele & shift)
                count++;
        }
        if(count % noOfTimeNoIsRepeating)
            ans += shift;

        shift *= 2;
    }
    return ans;
}

//`````````````````````````````````````````````````` //
// Aproach #3 // Time : O(N) // Space : O (1)    
// Using BIT Manipulation
//...............................................    
// ### works ONLY for all number occuring THREE TIMES except one
//```````````````````````````````````````````````    
//.................................................. //
int singleNumber3(vector<int> nums)
{
    int ones = 0; // store ele occuring single time
    int twos = 0; // store ele occuring two time
    for(auto ele:nums)
    {
        ones = (ones ^ ele) & (~twos); // (ones XOR ele) AND (complement(twos))
        twos = (twos ^ ele) & (~ones); // (ones XOR ele) AND (complement(ones)) // store ele occuring two time
    }
    return ones;
}

//`````````````````````````````````````````````````` //
// Aproach #4 // Time : O(N) // Space : O (1)    
// Using XOR only (ONLY if no. is repeating for EVEN time)
//.................................................. //
int singleNumber4(vector<int> nums)
{
    int result = 0;
    for(auto ele:nums)
        result ^= ele;
    return result;

    /*  XOR property
        x ^ x = 0
        x ^ 0 = x
        so same no. will down to zero and one single element will remain
    */
}

//`````````````````````````````````````````````````` //
// Aproach #5 // Time : O(N) // Space : O (1)    
// Using XOR only (ONLY if no. is repeating for EVEN time)
// This is for two single Number 
//.................................................. //
vector<int> singleNumber5(vector<int> nums)
{
    long long xy;
    for(auto it:nums)
        xy ^= it;
    xy &= -xy;
    vector<int> ans = {0,0};
    for(auto ele:nums)
    {
        if(xy & ele)
            ans[0] ^= ele;
        else
            ans[1] ^= ele;
    }
    return ans;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif  

    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &it:v)
        cin>>it;

    cout<< singleNumber4(v) <<endl;

    return 0;
} 