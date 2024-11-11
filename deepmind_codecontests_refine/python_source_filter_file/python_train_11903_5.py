k=int(input())
s=input()
n=len(s)
i1=0
dp=[0]*(n)
cnt=0
ind=[0]

if k==0:
    ocnt=0
    ans=0
    for i in range(n):
        if s[i]=='0':
            ocnt+=1
            
        else:
            ans += max((ocnt*(ocnt-1))//2,0)
            ocnt=0
            
    ans+=max((ocnt*(ocnt-1))//2,0)
    print(ans)
else:
    for i in range(n):
        if s[i]=='1':
            cnt+=1
            ind.append(i+1)
            if cnt>=k:
                dp[i]=ind[-k]-ind[-k-1]
                
        else:
            dp[i]=dp[i-1]
            
    print(sum(dp))
        
