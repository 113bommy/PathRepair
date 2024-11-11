import sys
input=sys.stdin.readline
n=int(input())
a=list(map(int,input().split()))
ch=[]
for i in range(n):
    ch.append((a[i],i))
ch.sort(reverse=True)
#print(ch)
dp=[[0]*(n+1) for _ in range(n+1)]
dp[1][1]=ch[0][0]*ch[0][1]
dp[1][0]=ch[0][0]*(n-1-ch[0][1])
for i in range(2,n+1):
    for j in range(i+1):
        if j>=1:
            dp[i][j]=max(dp[i][j],dp[i-1][j-1]+ch[i-1][0]*abs(ch[i-1][1]-j+1))
        if i-1>=j:
            dp[i][j]=max(dp[i][j],dp[i-1][j]+ch[i-1][0]*abs(n-i+j-ch[i-1][1]))
print(max(dp[n]))   