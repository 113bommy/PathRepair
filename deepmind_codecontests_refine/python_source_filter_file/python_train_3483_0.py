t,k=map(int,input().strip().split(' '))
q=[] 
mx=0
while t:
    t-=1 
    a,b=map(int,input().strip().split(' '))
    mx=max(mx,b)
    q.append([a,b])
dp=[0]*(mx+1)
for i in range(0,k):
    dp[i]=1 
dp[k]=2 
for i in range(k+1,mx+1):
    dp[i]=dp[i-1]+dp[i-k]
    dp[i]%=(10**9+7)
for i in range(1,mx+1):
    dp[i]=(dp[i-1]+dp[i])%(10**9+6)
for z in q:
    
    print((dp[z[1]]-dp[z[0]-1])%(10**9+6))