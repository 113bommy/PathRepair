n=int(input())
dp=[0,1]
for i in range(2,n+1):
    dp.append(dp[i-1]+2**i)
print(dp[n])