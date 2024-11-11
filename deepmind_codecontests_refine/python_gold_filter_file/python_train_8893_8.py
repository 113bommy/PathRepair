import sys
n,k,d = map(int,sys.stdin.readline().split()) 
dp = [0]*(n+1) 
dp1 = [0]*(n+1) 
dp[0]=dp1[0]=1 
mod = 1000000007
for i in range(1,n+1): 
    for j in range(1,k+1): 
        if(i<j): break
        dp[i]+=dp[i-j] 
for i in range(1,n+1): 
    for j in range(1,d): 
        if(i<j): break 
        dp1[i]+=dp1[i-j]
print((dp[n]-dp1[n])%mod)
    
