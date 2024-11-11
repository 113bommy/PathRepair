dp=[0]*(30002)
dp[1]=2
for i in range(2,30002):
    dp[i]=dp[i-1]+ 2*i+ i-1
#print(dp[-1])    
for _ in range(int(input())):
    n = int(input())
    ans=0
    i=30001
    while i>0 and n>0:
        if dp[i]<=n:
#            print(n,dp[i])
            n-=dp[i]
            ans+=1
            i+=1
        i-=1
    print(ans)        
            

