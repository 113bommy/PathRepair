mod=10**9+7

n=int(input())
s=input()[::-1]
#dp=[c,bc,abc]
dp=[[0]*3 for _ in range(n+1)]
pows=[1]
for i in range(n):
    pows.append((pows[-1]*3)%mod)
cnt=0
for i in range(n):
    if s[i]=='a':
        dp[i+1][0]+=dp[i][0]
        dp[i+1][1]+=dp[i][1]
        dp[i+1][2]+=dp[i][2]+dp[i][1]
    elif s[i]=='b':
        dp[i+1][0]+=dp[i][0]
        dp[i+1][1]+=dp[i][1]+dp[i][0]
        dp[i+1][2]+=dp[i][2]
    elif s[i]=='c':
        dp[i+1][0]+=dp[i][0]+1
        dp[i+1][1]+=dp[i][1]
        dp[i+1][2]+=dp[i][2]
    elif s[i]=='?':
        #a
        dp[i+1][0]+=dp[i][0]
        dp[i+1][1]+=dp[i][1]
        dp[i+1][2]+=dp[i][2]+dp[i][1]
        #b
        dp[i+1][0]+=dp[i][0]
        dp[i+1][1]+=dp[i][1]+dp[i][0]
        dp[i+1][2]+=dp[i][2]
        #c
        dp[i+1][0]+=dp[i][0]+pows[cnt]
        dp[i+1][1]+=dp[i][1]
        dp[i+1][2]+=dp[i][2]
        cnt+=1
    dp[i+1][0]%=mod
    dp[i+1][1]%=mod
    dp[i+1][2]%=mod
print(dp[n][2])