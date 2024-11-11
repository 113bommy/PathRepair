t=int(input())
for i in range(t):
    a,b=map(int,input().split())
    s=[]
    k=input()
    n=len(k)
    for j in k:
        s.append(int(j))

    res=[]
    c=-1
    for j in range(n):
        if s[j]==0:
            res.append(j-c-1)
            c=j



    if len(res)==0:
        print(a)

    else:
        l=len(res)
        dp=[[float("inf"),float("inf")] for i in range(l)]
        if res[0]>0:
            dp[0][0]=a
        else:
            dp[0][0]=0

        dp[0][1]=b+a
        j=1

        while(j<l):
            if res[j]==0:
                dp[j][0]=min(dp[j-1][0],dp[j-1][1])
                dp[j][1]=min(dp[j][1],dp[j-1][0]+b,dp[j-1][1]+b)

            else:
                dp[j][0]=min(dp[j-1][0]+a,dp[j-1][1])
                dp[j][1]=min(dp[j][1],dp[j-1][0]+a+b,dp[j-1][1]+b)

            j+=1


        if s[-1]==0:
            print(min(dp[-1][0],dp[-1][1]))

        else:
            print(min(dp[-1][0]+a,dp[-1][1]))











