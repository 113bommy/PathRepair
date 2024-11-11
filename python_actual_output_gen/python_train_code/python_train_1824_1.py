def gl(x):
    return x not in ['e', 'u', 'i', 'o', 'a']

s = input()
o = 0
print(s[:3], end = '')
for i in range(3, len(s)):
    if gl(s[i - 2]) and gl(s[i - 1]) and gl(s[i]) and (s[i - 2] != s[i - 1] or s[i - 1] != s[i]) and o + 1 < i:
        print(' ', end = '')
        o = i
    print(s[i], sep = '', end = '')