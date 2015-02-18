/**********************************************************
For example, the string aabcccccaaa would become a2b1c5a3.
If the “compressed” string would not become smaller than the
original string, you should return the original one.
**********************************************************/

string str_compress(const string &str) {
    string ret;
    if (str.size() == 0)
        return ret;
    int count = 1;
    char cur = str[0];
    int i = 1;
    while (i < str.size()) {
        if (i == str.size() - 1) {
            if (str[i] == cur) {
                count++;
                ret.push_back(cur);
                ret += std::to_string(count);
            }
            else {
                ret.push_back(cur);
                ret += std::to_string(count);
                ret.push_back(str[i]);
                ret += std::to_string(1);
            }
            break;
        }
        if (str[i] == cur)
            count++;
        else {
            ret.push_back(cur);
            ret += std::to_string(count);
            cur = str[i];
            count = 1;
        }
        i++;
    }
    return ret.size() < str.size() ? ret : str;
}