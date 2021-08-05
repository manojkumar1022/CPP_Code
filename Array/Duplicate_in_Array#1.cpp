/*
##############################
Find the Duplicate Number leetcode
https://leetcode.com/problems/find-the-duplicate-number/
##############################
*/ 


#include <bits/stdc++.h>
using namespace std;


//`````````````````````````````````````````````````` //
// Aproach #1 // Time : O(NlogN) // Space : O (logN) //
//.................................................. //
int singleDuplicate1(vector<int> nums)
{
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size()-1;i++)
    {
        if(nums[i] == nums[i+1])
            return nums[i];
    }
    return -1;
}


//``````````````````````````````````````````` //
// Aproach #2 // Time : O(N) // Space : O (N) //
//........................................... //
int singleDuplicate2(vector<int> nums)
{
    vector<int> v(nums.size(),0);
    for(int i=0;i<nums.size();i++)
    {
        if(!v[nums[i]])
            v[nums[i]]++;
        else
            return nums[i];
    }
    return -1;
}


//``````````````````````````````````````````` //
// Aproach #3 // Time : O(N) // Space : O (1) //
//........................................... //
/* # there must be an duplicate in array 
   # otherwise program will go in infinite    */

int singleDuplicate3(vector<int> nums)
{
    int slow;
    int fast;
    slow = fast = nums[0];

    do
    {   
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    while(slow != fast);

    slow = nums[0];
    while(slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif  


    /*
    ## v.size == n + 1
    ## 1 <= v[i] <= n
    */
    
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &it:v)
        cin>>it;

    cout<< singleDuplicate1(v) <<endl;
    cout<< singleDuplicate2(v) <<endl;


    return 0;
} 