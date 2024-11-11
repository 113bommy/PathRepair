n = int(input())
s = input().strip()
ans = 0
for i in range(n, len(s), n):
    ans += s[n - 3:n] == "bbb" or s[n - 3:n] == 'aaa'
print(ans)
