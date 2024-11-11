dp = [1,1,2]
for i in range(3,21):
    dp.append(dp[-1]*i)

n = int(input())
numer = dp[n]
denom = ((n/2)**2)
print (int(numer/(denom*2)))
