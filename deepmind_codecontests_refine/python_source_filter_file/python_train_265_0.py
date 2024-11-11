n = int(input())
s = input()

print(s[0], end = '')
for i in range(1, len(s)):
    if not(s[i - 1] == s[i] == 'a' or s[i - 1] == s[i] == 'i' or s[i - 1] == s[i] == 'u' or s[i - 1] == s[i] == 'y'):
        if i >= 2 and (i < len(s) - 1 and (s[i - 2] != s[i - 1] == s[i] == 'e' != s[i + 1] or s[i - 2] != s[i - 1] == s[i] == 'o' != s[i + 1]) or i == len(s) - 1 and (s[i - 2] != s[i - 1] == s[i] == 'e' or s[i - 2] != s[i - 1] == s[i] == 'o')) or i == 2 and (i < len(s) - 1 and (s[i - 1] == s[i] == 'e' != s[i + 1] or s[i - 1] == s[i] == 'o' != s[i + 1]) or i == len(s) - 1 and (s[i - 1] == s[i] == 'e' or s[i - 1] == s[i] == 'o')):
            print(s[i], end = '')
        elif not(s[i - 1] == s[i] == 'e' or s[i - 1] == s[i] == 'o'):
            print(s[i], end = '')
        