import sys
input=sys.stdin.readline
n=int(input())
c=list(map(int,input().split()))
dp=[[-1]*(n+1) for i in range(n+1)]
def calc(l,r):
    if l>r:
        return 0
    elif l==r:
        return 1
    elif dp[l][r]!=-1:
        return dp[l][r]
    res=10**9
    if c[l]==c[l+1]:
        res=min(res,calc(l+2,r)+1)
    for k in range(l+2,r+1):
        if c[l]==c[k]:
            res=min(res,calc(l,k-1)+calc(k+1,r))
    dp[l][r]=min(res,1+calc(l+1,r))
    return dp[l][r]
print(calc(0,n-1))