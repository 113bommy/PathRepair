mod=10**9+7
S=input()
dp=[0]*13
dp[0]=1

for s in S:
    prev=[x for x in dp]
    dp=[0]*13
    if s=='?':
        nx=range(10)
    else:
        nx=[int(s)]
    for i in range(13):
        for j in nx:
            dp[(10*i+j)%13]+=prev[i]
    dp=[x%mod for x in dp]
print(dp[5])