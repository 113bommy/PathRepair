import sys
sys.setrecursionlimit(2147483647)
INF=float("inf")
MOD=10**9+7
input=lambda :sys.stdin.readline().rstrip()
def resolve():
    from functools import cmp_to_key
    n=int(input())
    B=[list(map(int,input().split())) for _ in range(n)]
    def cmp(a,b):
        va=min(a[1],b[1]-a[0])
        vb=min(b[1],a[1]-b[0])
        if(va==vb): return 0
        return -1 if(va>vb) else 1
    B.sort(key=cmp_to_key(cmp))
    dp=[-INF]*(20101)
    dp[0]=0
    for i in range(n):
        w,s,v=B[i]
        ndp=dp[:]
        for total in range(10101):
            if(total<=s):
                ndp[total+w]=max(ndp[total+w],dp[total]+v)
        dp=ndp[:]
    print(max(dp[:10101]))
resolve()