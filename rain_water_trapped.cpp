/* Rain Water Trapped
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining. 
Input Format
The only argument given is integer array A.
Output Format
Return the total water it is able to trap after raining..
For Example
Input 1:
    A = [0,1,0,2,1,0,1,3,2,1,2,1]
Output 1:
    6
Explaination 1:

    In this case, 6 units of rain water (blue section) are being trapped.*/
    
    
    int Solution::trap(const vector<int> &A) {
    int n=A.size();
    if(n==0)
    return 0;
    
    vector<int>left(n);
    vector<int>right(n);
    int water_trap=0;
    
    left[0]=A[0];
    for(int i=1;i<n;i++)
        left[i]=max(left[i-1],A[i]);
        
    right[n-1]=A[n-1];
    for(int i=n-2;i>=0;i--)
        right[i]=max(right[i+1],A[i]);
        
    for(int i=0;i<n;i++)
    water_trap=water_trap + min(left[i],right[i])-A[i];

    return water_trap;
}
