n = int(input())
s = input().strip()
ans = 0
for i in range(n, len(s), n):
    ans += s[i - 3:i] == "bbb" or s[i - 3:i] == 'aaa'
print(ans)
