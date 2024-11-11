def abhi(x,good):


    if x==n:
        if l<=good<=r:
            return 1
        return 0
    elif dp[x][good] !=-1:
        return dp[x][good]
    else:
        s=0
        if l<=good<=r:
            s=1

        dp[x][good]= s+max(abhi(x+1 , (good+t[x]-1)%h),abhi(x+1,(good+t[x])%h))
        return dp[x][good]
            


        

n,h,l,r = map(int,input().split())


t = list(map(int,input().split()))


dp=[[-1 for i in range(h+1)] for j in range(n+1)]


print(abhi(0,0))
