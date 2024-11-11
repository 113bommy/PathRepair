s=input()
n=len(s)
s=[s[i] for i in range(n)]
s=s+s
dp=[0]*(2*n)
dp[0]=1
for i in range(1,2*n):
    if s[i]!=s[i-1]:
        dp[i]=dp[i-1]+1
    else:
        dp[i]=1

print(max(dp))
