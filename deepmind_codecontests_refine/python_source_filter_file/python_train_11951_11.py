# -*- coding: utf-8 -*-


N,K=map(int, input().split())
H=list(map(int, input().split()))
G=[0]
G.extend(H[:])

dp=[[0]*(N+1) for i in range(N-K+1)]


tempa=0
if K<N-1:
    for jtemp in range(N-1):
        j=jtemp+2
        dp[1][j]=G[j]#min(dp[1][j-1],G[j])
    for itemp in range(N-K-1):
        i=itemp+2
        for jtemp in range(N-(i-1)):
            j=jtemp+i
            temp=int(N*1e9)
            
            for ktemp in range(j-(i-1)):
                k=ktemp+i-1
                val=G[j]-G[k]
                if val<0:
                    val=0
                if temp>dp[i-1][k]+val:
                    temp=dp[i-1][k]+val
            dp[i][j]=temp
    tempa=dp[N-K][-1]
    for jtemp in range(N):
        j=jtemp+1
        if tempa>dp[N-K][j] and dp[N-K][j]!=0:
            tempa=dp[N-K][j]
elif N-K==1:
    tempa=min(H[:])
else:
    tempa=0
print(tempa)