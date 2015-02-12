/***********************************************************************
Given an array of whose elements are positive numbers. Find the maximum
sum of a subsequence with all the constraint that no two numbers in the
sequence should be adjacent in the array.
3 2 7 10 should return 13 (13 = 3 + 10)
3 2 5 10 7 should return 15 (15 = 3 + 5 + 7)
1 5 4 3 2 should return 8 (8 = 5 + 3)
***********************************************************************/

int maxvalue(int a[], int n) {
    int cur = a[0];
    int prev = 0;
    for (int i = 1; i < n; i++) {
        int backup = cur;
        cur = std::max(cur, prev + a[i]);
        prev = backup;
    }
    return cur;
}