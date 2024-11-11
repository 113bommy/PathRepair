t=int(input());a=[]
dp=[0]+[1]+[0]*99999
for i in range(2,100001):
    if i%2==1:
        dp[i]=i-dp[i-1]
    else:
        if i%4==0 and i>4:
            dp[i]=dp[i-2]+1
        else:
            dp[i]=dp[i//2-1]+i//2
for _ in range(t):
    n=int(input())
    ans=0;r=n
    while r>100000:
        if r%2==0:
            if r%4==0:
                ans+=1;r-=2
            else:
                ans+=r//2;r//=2;r-=1
        else:
            r-=1;ans+=1
            if r%4!=0:
                r//=2
            else:
                r-=1
    ans+=dp[r]
    a.append(ans)
for x in a:
    print(x)