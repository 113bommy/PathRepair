k = int(((10**9)*2 - 1)**0.5) 
dp = [0]*(k+1)

for a in range(1,k+1):
    if (a**2)%2!=0:
        if a**2 - 1>0:
            dp[a] = dp[a-1] + 1 
        else:
            dp[a] = dp[a-1] 
    else:
        dp[a] = dp[a-1]
            

#print(dp)
for _ in range(int(input())):
    n = int(input())
    n = int((2*n - 1)**0.5)
    ans = dp[n]
    print(ans)