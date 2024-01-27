#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s)
{
    int len = strlen(s);
    int start = 0, end = 0, result = 0;
    int map[128] = {0};

    while (end < len)
    {
        if (map[s[end]] == 0)
        {
            map[s[end]] = 1;
            end++;
            if (end - start > result)
            {
                result = end - start;
            }
        }
        else
        {
            map[s[start]] = 0;
            start++;
        }
    }
    return result;
}

int main()
{
    char *s = "abcabcbb";
    int result = lengthOfLongestSubstring(s);
    printf("result: %d\n", result);
    return 0;
}