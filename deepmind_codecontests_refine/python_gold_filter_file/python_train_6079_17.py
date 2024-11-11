s = input()
m = int(input())

o = 0
dp = [0]
for i in range(len(s) - 1):
    if s[i] == s[i + 1]:
        o += 1
    dp.append(o)

# print(dp)
ans = []
for _ in range(m):
    i, j = map(int, input().split())
    ans.append(dp[j-1] - dp[i-1])

print('\n'.join(map(str, ans)))
