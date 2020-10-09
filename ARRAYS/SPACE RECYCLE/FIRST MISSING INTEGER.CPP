int Solution::firstMissingPositive(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=A.size();
    int j=0;
    for(int i=0;i<n;i++){
        if(A[i]<=0){
            swap(A[i],A[j]);
            j++;
        }
    }
    for(int i=j;i<n;i++){
        if(abs(A[i])+j-1>=0&&abs(A[i])+j-1<n){
         if(A[abs(A[i])+j-1]>0)
           A[abs(A[i])+j-1]=-A[abs(A[i])+j-1];
        }
    }
    for(int i=j;i<n;i++){
       // cout<<A[i]<<"\n";
        if(A[i]>0)
         return (i-j+1);
    }
    return (n-j+1);
}
