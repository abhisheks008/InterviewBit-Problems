int Solution::solve(vector<int> &A, int B, int C) {
    if(A.size()==0) {
        return 0;
    }
    // sort(A.begin(),A.end());
    string Cstr = to_string(C);
    if(Cstr.size()<B) {
        return 0;
    } else if(Cstr.size()>B) {
        if(B==1) {
            return A.size();
        }
        if(A[0]==0) {
            return (A.size()-1)*pow(A.size(),B-1);
        } else {
            return pow(A.size(),B);
        }
    } else {

        vector<bool> isthere(10,false);
        for(int i=0;i<A.size();i++) {
            isthere[A[i]] = true;
        }
        
        vector<int> lower(11,0);
        for(int i=0;i<A.size();i++) {
            for(int j=A[i]+1;j<11;j++) {
                lower[j]++;
            }
        }

        if(B==1) {// C = 10 A = 0,1  B=2    
            int temp = lower[Cstr[0]-'0'];
            if(temp==0&&isthere[0]) {
                return 1;
            } else {
                return temp;
            }
        }
        
        bool same = true;
        vector<int> arr(B,0);
        arr[0]=lower[Cstr[0]-'0'+1];
        if(A[0]==0) {
            arr[0]--;
        }
        if(!isthere[Cstr[0]-'0']) {
            same = false;
        }
        for(int i=1;i<B;i++) {
            if(same) {
                arr[i]+=(arr[i-1]-1)*A.size();
                arr[i]+=lower[Cstr[i]-'0'+1];
                if(!isthere[Cstr[i]-'0']) {
                    same = false;
                }
            } else {
                arr[i]+=arr[i-1]*A.size();
            }
        }
        if(same) {
            return arr[B-1]-1;
        } else {
            return arr[B-1];
        }
        
    }
}
