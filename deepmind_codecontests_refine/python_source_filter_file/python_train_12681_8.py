s = input()
n = len(s)
t = input()
m = len(t)

dp = [[0 for _ in range(m+1)] for _ in range(n+1)]

for i in range(n):
    for j in range(m):
        if t[j]!=s[i]:
            dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1])
        else :
            dp[i+1][j+1]=dp[i][j]+1

ans = ''

i = len(s)
j = len(t)
while (i>0  and j>0):
    if dp[i][j] == dp[i-1][j]:
        i -= 1
    elif dp[i][j] == dp[i][j-1]:
        j -= 1
    else:
        ans += s[i-1]
        i -= 1
        j -= 1

print(ans[::-1])
