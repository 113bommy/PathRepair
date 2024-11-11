s = input()

ans = 10**5
for i in range(len(s)-1):
    if s[i] != s[i+1]:
        ans = min(ans, max(i+1, len(s)-(i+1)))
print(ans)