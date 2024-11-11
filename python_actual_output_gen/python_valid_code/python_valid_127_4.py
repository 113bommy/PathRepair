n,m=map(int,input().split())
l=[int(x) for x in input().split()]
l.sort()
dp=[0]*n
for i in range(n):
    dp[i]=l[i]
    if i>=2:
        dp[i]+=dp[i-m]
t=0
ans=[]
for i in dp:
    t+=i
    ans.append(t)
print(*ans)
    