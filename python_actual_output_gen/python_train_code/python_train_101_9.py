s = list(input())
ans = 'NO'
for i in range(len(s)):
    if ''.join(s[:i] + s[n-7+i:]) == 'keyence':
        ans = 'YES'
        break
print(ans)        