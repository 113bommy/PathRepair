n,t=map(int,input().split())
dp=[0]*(t+3005)
ans=chk=0
w=[]
for i in range(n):
    a,b=map(int,input().split())
    w.append((a,b))
w.sort()

for i in w:
    for j in range(t-1,-1,-1):
        dp[j+i[0]]=max(dp[j+i[0]],dp[j]+i[1])
        ans=max(ans,dp[j+i[0]])
print(ans)