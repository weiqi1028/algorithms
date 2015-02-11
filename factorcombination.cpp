/*********************************************************************
Print all unique combination of factors (except 1) of a given number.
For example:
Input: 12
Output: [[2, 2, 3], [2, 6], [3, 4]]
Input: 15
Output: [[3, 5]]
Input: 28
Output: [[2, 2, 7], [2, 14], [4, 7]]

Solution: DFS, be care of duplicate results.
**********************************************************************/

void solve(int n, vector<int> &cur, vector<vector<int>> &result) {
    int last = cur.empty()? 2: cur.back();
    for (int i = last; i < n; i++) {
        if (n % i == 0) {
            cur.push_back(i);
            solve(n / i, cur, result);
            cur.pop_back();
        }
    }
    if (!cur.empty() && n >= cur.back()) {
        cur.push_back(n);
        result.push_back(cur);
        cur.pop_back();
    }
}

vector<vector<int>> factorComb(int n) {
    vector<vector<int>> result;
    vector<int> cur;
    solve(n, cur, result);
    return result;
}