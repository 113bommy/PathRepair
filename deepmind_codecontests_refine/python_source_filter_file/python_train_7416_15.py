dp=[0]*(20002)
dp[1]=2
for i in range(2,20002):
    dp[i]=dp[i-1]+ 2*i+ i-1
#print(dp[:10])    
for _ in range(int(input())):
    n = int(input())
    ans=0
    i=20000
    while i>0 and n>0:
        if dp[i]<=n:
#            print(n,dp[i])
            n-=dp[i]
            ans+=1
            i+=1
        i-=1
    print(ans)        
            

