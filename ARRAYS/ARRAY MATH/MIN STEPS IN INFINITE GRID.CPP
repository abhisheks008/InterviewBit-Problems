int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    size_t sz = A.size();   // Not comparing the sizes of A & B since 'Expected output' shows this as an invalid test case.
    int steps = 0;
    for (size_t i = 0; i < sz - 1; ++i)
        steps += max(abs(A[i] - A[i+1]), abs(B[i] - B[i+1]));
    return steps;
}
