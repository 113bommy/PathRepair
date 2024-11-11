n = int(input().strip())
ans = 0
s = input().strip()
for i in range(n, len(s), n):
    if s[i - 1] == s[i - 2] == s[i - 3]:
        ans += 1

print(ans)