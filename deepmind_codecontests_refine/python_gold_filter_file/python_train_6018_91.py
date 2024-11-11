S=input()
MOD=10**9+7
dp=[0]*13
dp[0]=1
for s in S:
    p=[x for x in dp]
    dp=[0]*13
    if s=="?":
        a=range(10)
    else:
        a=[int(s)]
    for i in range(13):
        for x in a:
            dp[(10*i+x)%13]+=p[i]
    dp=[x%MOD for x in dp]
print(dp[5])