n = int(input())
s = [int(i) for i in input().split()]
ss = [int(i) for i in input().split()]
dp = [0]*n
dpp = [0]*n
if n > 1:
    for i in range(0,n):
        dp[i] = max(dpp[i-1],dpp[i-2])+s[i]
        dpp[i] = max(dp[i-1],dp[i-2])+ss[i]
    print(max(dp[-1],dpp[-1]))
else:
    print(max(s[0],ss[0]))