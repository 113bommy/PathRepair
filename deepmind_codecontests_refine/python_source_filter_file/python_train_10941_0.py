from sys import stdin,stdout
nmbr = lambda: int(input())
lst = lambda: list(map(int, input().split()))
PI=float('inf')
def fn(pos,mask):
    if mask==7:return 0
    if pos==0:return PI
    inc=l[pos-1][0]+fn(pos-1,mask | l[pos-1][1])
    skip=fn(pos-1,mask)
    return min(inc,skip)
for _ in range(1):#nmbr()):
    n=nmbr()
    l=[]
    ans=PI
    for i in range(n):
        nn,ss=input().split()
        nn=int(nn)
        mask=0
        if 'A' in ss:mask|=1<<0
        if 'B' in ss:mask|=1<<1
        if 'C' in ss:mask|=1<<2
        l+=[[nn,mask]]
    # print(fn(n,0))
    dp=[[PI for i in range(8)]for i in range(n+1)]
    dp[0][0]=0
    for i in range(n):
        for j in range(7):
            dp[i+1][j | l[i][1]] = min(dp[i+1][j | l[i][1]],l[i][0]+dp[i][j])
            dp[i+1][j]=min(dp[i+1][j],dp[i][j])
    # print(*dp,sep='\n')
    for i in range(n):
        ans=min(dp[i][7],ans)
    print(ans if ans!=PI else -1 )
    # dp[n][0]=0
    # for i in range(n,0,-1):
    #     for j in range(8):
    #         dp[i-1][j | l[i-1][1]] = min(dp[i-1][j | l[i-1][1]], l[i-1][0] + dp[i][j])
    #         dp[i-1][j] = min(dp[i-1][j] , dp[i][j])
    # print(dp[0][7] if dp[0][7]!=PI else -1)