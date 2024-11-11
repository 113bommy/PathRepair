ans=0
n,t=map(int,input().split())
food=[]
for i in range(n):
    f=list(map(int,input().split()))
    food.append(f)
food=sorted(food)
dp=[0,0]+[-1]*(t-1)

for a,b in food:
    tmp=[dp[i] for i in range(t)]
    for i in range(t):
        if dp[i]==-1: continue
        j=i+a
        if j<t: tmp[j]=max(tmp[j],dp[i]+b)
        else: ans=max(ans,dp[i]+b)
    
    dp=[tmp[i] for i in range(t)]
print(max(ans,max(dp)))