// A string can be shortened by replacing any number of non-adjacent, non-empty substrings with
// their lengths (without leading zeros).

// For example, the string "implementation" can be abbreviated in several ways, such as:

// "i12n" -> ("i mplementatio n")
// "imp4n5n" -> ("imp leme n tatio n")
// "14" -> ("implementation")
// "implemetation" -> (no substrings replaced)
// Invalid abbreviations include:

// "i57n" -> (i mplem entatio n, adjacent substrings are replaced.)
// "i012n" -> (has leading zeros)
// "i0mplementation" (replaces an empty substring)
// You are given a string named word and an abbreviation named abbr, return true if abbr correctly abbreviates word, otherwise return false.

// A substring is a contiguous non-empty sequence of characters within a string.

// Example 1:

// Input: word = "apple", abbr = "a3e"

// Output: true
// Example 2:

// Input: word = "international", abbr = "i9l"

// Output: false
// Example 3:

// Input: word = "abbreviation", abbr = "abbreviation"

// Output: true

#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validwordAbbreviation(string word, string abbr) {
        int i = 0;
        int j = 0;

        // T: O(m + n), S: O(1)
        while (i < word.length() && j < abbr.length()) {
            char w_c = word[i];
            char a_c = abbr[j];

            if (isdigit(a_c)) {
                // leading zero is invalid
                if (a_c == '0')
                    return false;

                int curr = 0;

                while (j < abbr.length() && isdigit(abbr[j])) {
                    curr = curr * 10 + (abbr[j] - '0');
                    j++;
                }

                i = i + curr;
            } else {
                if (w_c != a_c)
                    return false;

                i = i + 1;
                j = j + 1;
            }
        }

        return i == word.length() && j == abbr.length();
    }
};
int main() {
    Solution sol;
    string word = "apple";
    string abbr = "a3e";
    bool result = sol.validwordAbbreviation(word, abbr);

    cout << (result ? "true" : "false") << endl;
    return 0;
}
