n=int(input())
l=list(map(int,input().split()))
dp=[[0 for j in range(n+1)] for i in range(n+1)]
e=[]
for i in range(n):
    e.append([l[i],i])
e.sort(reverse=True)
for i in range(1,n+1):
    p=e[i-1][0]
    q=e[i-1][1]
    for j in range(i+1):
        if j<i:
            a1=dp[i-1][j]+p*abs(n-(i-j)-q)
        else:
            a1=0
        if j>0:
            a2=dp[i-1][j-1]+p*abs(q-j+1)
        else:
            a2=0
        dp[i][j]=max(a1,a2)
print(max(dp[-1]))
