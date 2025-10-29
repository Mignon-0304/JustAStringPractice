# JustAStringPractice

Because the TA is too tired to develop a story, the following is the direct problem statement.
You have an initially empty string s, and you need to perform n operations on it.
Each operation can be one of the following seven types:

APPEND "ai": Append the string ai to the end of s.

COMPARE "bi": Compare the current string s with the string bi, in a case-insensitive manner. For example, 'E' is considered equal to 'e'.

COUNT "ci": Count the number of times the substring ci occurs in s, which is case-sensitive. Overlapping occurrences are counted separately.

BACKSPACE "di": Delete the last di characters from s. If di exceeds the current length of s, s becomes empty.

TOUPPER: Convert all lowercase letters in s to uppercase.

TOLOWER: Convert all uppercase letters in s to lowercase.

PRINT: Output the current state of the string s, surrounded by double quotation marks(").

SWAP 'xi' 'yi': Besides the string s, you also have a custom order of characters, which initially is as follows:

'\0' < ' ' < 'a' < 'b' <...< 'z'

Here, '\0' represents the null character(empty string), and ' ' represents the space character. Since the compare operation is case-insensitive, we only consider lowercase letters in this custom order. For each swap operation, it will swap the order of character xi and character yi in this custom order. For example, if the custom order is initially as above, after performing swap 'a' 'b', the custom order becomes:

'\0' < ' ' < 'b' < 'a' <...< 'z'

For each compare operation, you must compare the strings according to the current custom order instead of the standard lexicographical order. For example, if you want to compare "ca" and "cb" and the current custom order is:

'\0' <' '< 'b' < 'a' <...< 'z'

You can start by considering "ca" as "ca\0" and "cb" as "cb\0", then compare them character by character: 
First character: 'c' = 'c', so continue to the next character. 
Second character: 'a' >'b' in the current custom order, so "ca" is greater than "cb". 
Note that, for each count operation, you don't need to consider the null character. For example, "ca" you don't need to consider it as "ca\0". 

constraints:

#1 1<=n<=5*10^3

#2 ai, bi, ci are strings that may contain lowercase letters, uppercase letters, and space characters(' ').

#3 ai, bi can be empty, but ci cannot.

#4 di is an integer, 0<=di<=10^9

#5 xi, yi are lowercase letters, space character(' '), or null character('\0').

#6 xi!=yi 

#7 It is guaranteed that the total length in all ai, bi does not exceed 10^7

#8 It is guaranteed that the total length in all ci does not exceed 5*10^3

#9 It is guaranteed that the maximum length of s at any time does not exceed 10^4