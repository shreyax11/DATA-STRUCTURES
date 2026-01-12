//valid Palindrome
//Problem: Check if string is palindrome ignoring non-alphanumeric chars.
//Example: "A man, a plan, a canal: Panama" → True
//Topic: Strings, Two Pointers

#include <stdio.h>
#include <ctype.h>
#include <string.h>
int isPalindrome(char *s) {
    int left = 0;
    int right = strlen(s) - 1;
    while (left < right) {
        if (!isalnum(s[left])) 
        {
            left++;
            continue;
        }
        if (!isalnum(s[right])) 
        {
            right--;
            continue;
        }
        if (tolower(s[left]) != tolower(s[right])) 
        {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}
int main() {
    char str[] = "A man, a plan, a canal: Panama";
    if (isPalindrome(str)) {
        printf("True\n");
    } else {
        printf("False\n");
    }
    return 0;
}
