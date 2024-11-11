for _ in range(int(input())):
    (planes,k)=(int(x) for x in input().split())
    if k==1:
        print(1)
        continue
    if planes==1:
        print(2)
        continue
    d={}
    d[k]=1
    ans=0
    temp=k
    dp={}
    planes-=1
    mod=1000000007
    for i in range(k,-1,-1):
        dp[i]=[]
    for i in range(k,-1,-1):
        for j in range(planes+1):
            dp[i].append(0)
    dp[k][planes]=1
        
    for i in range(k-1,-1,-1):
        par=0
        for j in range(planes,0,-1):
            par=((par%mod)+(dp[i+1][j]%mod))%mod
            dp[i][planes-j+1]=par
    # print("======")
    # for i in range(k,-1,-1):
    #     print(*dp[i])
    for i in range(k,-1,-1):
        ans=((ans%mod)+(dp[i][planes]%mod))%mod
    print(ans)