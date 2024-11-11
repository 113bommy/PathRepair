from math import inf

n,m,x,y=map(int,input().split())
matx=[]
for i in range(n):
    matx.append(list(input().strip()))

d=[[0,0]]
for i in range(m):
    c=0
    for j in range(n):
        if matx[j][i]=='.':
            c+=1
    d.append([c,n-c])

print(d)
for i in range(1,m+1):
    d[i][0]+=d[i-1][0]
    d[i][1]+=d[i-1][1]
#dp[n][0,1][p]

dp=[[1000,1000]for j in range(m+1)]
dp[0]=[0,0]
dp[x]=[d[x][0],d[x][1]]
for i in range(x,m+1):
    for j in range(x,min(y+1,i+1)):
        dp[i][0]=min(dp[i-j][1]+d[i][0]-d[i-j][0],dp[i][0])

        dp[i][1]=min(dp[i-j][0]+d[i][1]-d[i-j][1],dp[i][1])
#A&print(dp)
print(min(dp[-1]))
