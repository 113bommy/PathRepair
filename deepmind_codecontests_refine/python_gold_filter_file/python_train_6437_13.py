s = input()
"""
s = '101'
s = '100000000'
s = '00001011'
"""
k = len(s)
for i in range(1, len(s)):
    if s[i-1] != s[i]:
        k = min(k, max(i, len(s)-i))
print(k)


