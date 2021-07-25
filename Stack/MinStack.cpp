/*
##############################
MinStack Problem with Extra Space LeetCode
[https://leetcode.com/problems/min-stack/](https://leetcode.com/problems/min-stack/)
##############################
*/ 

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    stack<int> ss;
    
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(ss.size() ==0 || ss.top() >= val){
            ss.push(val);
        }
    }
    
    void pop() {
        if(s.size() !=0){
            if(s.top() == ss.top()){
                ss.pop();
            }
            s.pop();
        }
    }
    
    int top() {
        if(s.size() == 0 ){
            return -1;
        }
        return s.top();
    }
    
    int getMin() {
        if(ss.size()==0){
            return -1;
        }
        return ss.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


/*
.
.
.
.
.
*/


/*
##############################
MinStack Problem with O(1) Space GeeksforGeeks
[https://practice.geeksforgeeks.org/problems/special-stack/1](https://practice.geeksforgeeks.org/problems/special-stack/1)
##############################
*/ 

// { Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,a;
        cin>>n;
        while(!isEmpty(s)){
            pop(s);
        }
        while(!isFull(s,n)){
            cin>>a;
            push(s,a);
        }
        cout<<getMin(s)<<endl;
    }
}// } Driver Code Ends

int me = -1;
void push(stack<int>& s, int a){
    // Your code goes here
    if(s.size()==0){
        s.push(a);
        me = a;
    }
    else if(a > me){
        s.push(a);
    }
    else if(a <= me){
        s.push(2 * a - me);
        me = a;
    }
}

bool isFull(stack<int>& s,int n){
    // Your code goes here
    if(s.size() == n)
        return 1;
    return 0;
}

bool isEmpty(stack<int>& s){
    // Your code goes here
    if(!s.size())
        return 1;
    return 0;
}

int pop(stack<int>& s){
    // Your code goes here
    int ans;
    if(!s.size()){
        return -1;
    }
    else{
        if(s.top() >= me){
            ans =  s.top();
            s.pop();
        }
        else{
            ans =  s.top();
            me = 2 * me - ans;
            s.pop();
        }
        return ans;
    }
}

int getMin(stack<int>& s){
    // Your code goes here
    if(!s.size())
        return -1;
    return me;
}
