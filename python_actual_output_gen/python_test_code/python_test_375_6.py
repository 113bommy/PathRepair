mod = 1000000007
s=input()
n=len(s)
if 'w' in s or 'm' in s or n==1:
    print(0)
    exit()


dp = [0]*(n+1)
dp[1]=1
dp[0]=1
for i in range(2,n+1):
    dp[i]=dp[i-1]
    if s[i-1]==s[i-2] and (s[i-1]=='u' or s[i-1]=='n'):
        dp[i]=dp[i-1]+dp[i-2]
        dp[i]%=mod
print(dp[n])
