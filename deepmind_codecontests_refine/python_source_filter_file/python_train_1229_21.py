n,k=map(int,input().split())
a=list(map(int,input().split()))

dp=[False]*(k+1)
for i in range(0,k+1):
    for j in a:
        if i>=j and  dp[i-j]==False:
            dp[i]=True 
            
print(dp)
print ("First" if dp[k] else "Second")