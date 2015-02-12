/*********************************************************
Given two strings, write a function to decide if one is a
permutation of the other.
*********************************************************/

bool checkPermutation(string a, string b) {
    if (a.size() != b.size())
        return false;
    int count[256] = { 0 };
    for (int i = 0; i < a.size(); i++) {
        count[a[i]]++;
        count[b[i]]--;
    }
    for (int i = 0; i < 256; i++)
        if (count[i] != 0)
            return false;
    return true;
}