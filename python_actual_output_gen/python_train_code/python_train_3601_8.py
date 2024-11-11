s = input()
ans = 0
for i in range(len(s)):
    if s[i] == 'Q':
        ans += s[i:].count('A') * s[i:].count('Q')
print(ans)