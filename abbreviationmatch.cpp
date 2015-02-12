/************************************************************************
Abbreviation: apple can be abbreviated to 5, a4, 4e, a3e, …
If given a string and an abbreviation, return if the string matches abbr.
Assume the original string only contains alphabetic characters.
For example:
“internationalization”, “i5a11o1” -> true
*************************************************************************/

bool abbrMatch(string str, string abbr) {
    int i = 0;
    int j = 0;
    int num = 0;
    while (i < str.size() && j < abbr.size()) {
        char c = abbr[j];
        if (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
            if (j == abbr.size() - 1) {
                i += num;
            }
        }
        else {
            if (num != 0) {
                i += num;
                num = 0;
            }
            if (i >= str.size() || c != str[i])
                break;
            i++;
        }
        j++;
    }
    return i == str.size() && j == abbr.size();
}