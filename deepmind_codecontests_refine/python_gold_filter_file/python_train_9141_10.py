from copy import deepcopy
N=int(input())
A=[int(i) for i in input().split()]

def chmax(a,b):
    if a[0]<b[1]:
        return b
    elif a[0]<b[0]:
        return(b[0],a[0])
    elif a[1]<b[0]:
        return (a[0],b[0])
    else:
        return a
dp=[(A[i],0) for i in range(1<<N)]
#print(dp)
for i in range(N):
    for j in range(1<<N):
        if (j & (1<<i))==0:
            #print(j,i,j|(1<<i))
            dp[j|(1<<i)]=chmax(dp[j],dp[j|(1<<i)])
#print(dp)
ans =sum(dp[0])
for i in range(1,1<<N):
    t = sum(dp[i])
    ans = max(ans,t)
    print(ans)