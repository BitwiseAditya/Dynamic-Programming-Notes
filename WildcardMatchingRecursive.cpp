/* Problem statement
Given a text and a wildcard pattern of size N and M respectively, 
implement a wildcard pattern matching algorithm that finds if the 
wildcard pattern is matched with the text. The matching should cover 
the entire text not partial text.

The wildcard pattern can include the characters ‘?’ and ‘*’

 ‘?’ – matches any single character 
 ‘*’ – Matches any sequence of characters(sequence can be of length 0 or more)
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100
1 <= N <= 200
1 <= M <= 200

Where 'N' denotes the length of 'TEXT' and 'M' denotes the length of 'PATTERN'.

'TEXT' and 'PATTERN' contain only lowercase letters and patterns may contain special characters ‘*’ and ‘?’

Time Limit: 1sec
Sample Input 1:
3
?ay
ray
ab*cd
abdefcd
ab?d
abcc
Sample Output 1:
True
True
False
Explanation of the Sample Input1:
Test Case 1:
The pattern is “?ay” and the text is ray.
‘?’ can match a character so it matches with a character ‘r’ of the text and rest of the text matches with the pattern so we print True.

Test Case 2:
“ab” of text matches with “ab” of pattern and then ‘*’ of pattern matches with “def” of the text and “cd” of text matches with “cd” of the pattern. Whole text matches with the pattern so we print True.

Test Case 3:
“ab” of pattern matches with “ab” of text. ‘?’ of pattern matches with ‘c’ of the text but ‘d’ of the pattern do not match with ‘c’ of the text so we print False.
Sample Input 1:
1
ba*a?
baaabab
Sample Output 1:
True */

#include <bits/stdc++.h>
using namespace std;
bool f(int index1, int index2, string & pattern, string & text){
   if(index1 < 0 && index2 < 0) return true;
   if(index1 < 0 && index2 >= 0) return false;
   if(index1 >= 0 && index2 < 0){
       for (int i = index1; i >= 0; i--) {
        if (pattern[i] != '*') return false;
    }
    return true;
   }
   if(pattern[index1] == text[index2] || pattern[index1] == '?'){
      return f(index1 - 1, index2 - 1, pattern, text);
   }
   if(pattern[index1] == '*'){
      return f(index1 - 1, index2, pattern, text) | f(index1, index2 - 1, pattern, text);
   }
   return false;
}
bool wildcardMatching(string pattern, string text)
{
   // Write your code here.
   int n = pattern.length();
   int m = text.length();
   return f(n-1,m-1,pattern,text);
}


