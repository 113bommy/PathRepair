from sys import stdin,stdout
nmbr = lambda: int(stdin.readline())
lst = lambda: list(map(int,input().split()))
def fn(a):
    mp={}
    b=[]
    cnt=0
    for v in a:
        if v in mp:b+=[mp[v]]
        else:
            b+=[cnt]
            mp[v]=cnt
            cnt+=1
    return b
for i in range(1):#nmbr()):
    n=nmbr()
    a=fn(lst())
    N=max(a)+1;ans=0
    dp=[[1 for _ in range(N)]for j in range(n)]
    for i in range(1,n):
        for j in range(i):
            dp[i][a[j]]=1+dp[j][a[i]]
            ans=max(ans,dp[i][a[j]])
    # print(*dp,sep='\n')
    print(ans)