/*
##############################
Sort Colors leetcode
https://leetcode.com/problems/sort-colors/
````````````````````````````````````````````
Sort Colors gfg
https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
https://practice.geeksforgeeks.org/problems/binary-array-sorting-1587115620/1

```````````````````````````````````````````````````````````````
##############################
*/ 

#include<bits/stdc++.h>
using namespace std;

//`````````````````````````````````````````````````` //
// Aproach #1 // Time : O(N*logN) // Space : O (1)    
// Using Sorting
//.................................................. //
void sortColors1(vector<int>& nums) {
    
    sort(nums.begin(),nums.end());

}

//`````````````````````````````````````````````````` //
// Aproach #2 // Time : O(2*N) // Space : O (1)    
// Simple Counting
//.................................................. //
void sortColors2(vector<int>& nums) {
        
    int zeros,ones,twos;
    zeros = ones = twos = 0;
    int j = 0,i;
    for(i=0;i<n;i++){
        a[i] == 0 ? zeros++ : a[i] == 1 ? ones++ : twos++;
    }
    i = 0;
    while(zeros) {
        a[i] = 0;
        i++;
        zeros--;
    }
    while(ones) {
        a[i] = 1;
        i++;
        ones--;
    }
    while(twos) {
        a[i] = 2;
        i++;
        twos--;
    }
}

//`````````````````````````````````````````````````` //
// Aproach #3 // Time : O(N) // Space : O (1)
//_____________________________________    
// ## Dutch National Flag Algorithm
//``````````````````````````````````````
//.................................................. //
void sortColors2(vector<int>& nums) {
    
    int low = 0,mid=0,high=nums.size()-1;
    
    while(mid<=high)
    {
        switch(nums[mid])
        {
            case 0: swap(nums[mid],nums[low]);
                    mid++; low++;
                    break;
            case 1: mid++;
                    break;
            case 2: swap(nums[mid],nums[high]);
                    high--;
                    break;
        }
    }
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif  

    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &it:v)
        cin>>it;

    cout<< sortColors1(v) <<endl;
    cout<< sortColors2(v) <<endl;
    cout<< sortColors3(v) <<endl;

    return 0;
}