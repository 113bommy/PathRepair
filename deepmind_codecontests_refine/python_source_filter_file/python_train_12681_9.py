s = input()
t = input()

dp = [[0] * (len(t) + 1) for _ in range(len(s) + 1)]

for i, ei in enumerate(s, 1):
    for j, ej in enumerate(t, 1):
        dp[i][j] = max(dp[i-1][j], dp[i][j-1], (dp[i-1][j-1] + 1) * (ei == ej))

i = len(s)
j = len(t)
ans = []
while i and j:
    if dp[i-1][j] == dp[i][j]:
        i -= 1
    elif dp[i][j-1] == dp[i][j]:
        j -= 1
    else:
        ans.append(s[i-1])
        i -= 1
        j -= 1

ans = "".join(ans[::-1])
print(ans)
