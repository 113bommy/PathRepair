import math 
a=int(input())
z=list(map(int,input().split()))
ans=[]
for i in range(a):
    s=input()
    ans.append(s)
dp=[[math.inf for i in range(a)] for i in range(2)]
dp[0][0]=0
dp[1][0]=z[0]
for i in range(1,len(ans)):
    
    if(ans[i]>=ans[i-1]):
        dp[0][i]=min(dp[0][i-1],dp[0][i])
    if(ans[i][::-1]>=ans[i-1]):
        dp[1][i]=min(dp[1][i],dp[0][i-1]+z[i])
    if(ans[i]>=ans[i-1][::-1]):
        dp[0][i]=min(dp[0][i],dp[1][i-1])
    if(ans[i][::-1]>=ans[i-1][::-1]):
        dp[1][i]=min(dp[1][i],dp[1][i-1]+z[i])
x=min(dp[0][-1],dp[1][-1])
if(x==math.inf):
    print(-1)
else:
    print(x)
    
        
        
    
    
