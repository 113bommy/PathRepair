from bisect import bisect
mod = 10**9+7
N,K = map(int,input().split())

c = []
for i in range(1,int(N**0.5)+1):
    c.append(i)
    c.append(int(N/i))
c = list(set(c))
c.sort()

k = []
for i in c:
    if int(N/i) != int(N/(i+1)):
        k.append(i)

dp = [[0]*len(k) for _ in range(K)]
for i in range(len(k)):
    dp[0][i]=k[i]

inv = [0]*(len(k)-1)
for i in range(len(k)-1):
    inv[i] = pow(k[i+1]-k[i],mod-2,mod)

index = [0]*len(k)
for i in range(len(k)):
    m = int(N/(k[i]+1))
    index[i] = bisect(k,m)

for i in range(K-1):
    dp[i+1][0] = dp[i][-1]
    for j in range(len(k)-1):
        m = int(N/(k[j]+1))
        l = index[j]
        S = dp[i][l-1]+(dp[i][l]-dp[i][l-1])*(m-k[l-1])*inv[l-1]
        dp[i+1][j+1] = dp[i+1][j]+(k[j+1]-k[j])*S
        dp[i+1][j+1] %= mod

print(dp[-1][-1])