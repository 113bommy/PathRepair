s = input().split('*')
ans = -1
for i in range(len(s)):
    for j in range(1, len(s)):
        copy = s[:i] + [str(eval('*'.join(s[i:i + j])))] + s[i + j:]
        ans = max(ans, eval('*'.join(copy)))
print(ans)