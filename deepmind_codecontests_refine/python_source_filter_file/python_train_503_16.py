n, a =map(int, input().split())
x=list(map(int, input().split()))
x=[i-a for i in x]
memo=[[-1]*100000 for i in range(60)]
def dp(k, value):
    if k==n:
        if value==0:
            return 1
        else:
            return 0
    if memo[k][value]>0:
        return memo[k][value]
    memo[k][value]=dp(k+1, value+x[k])+dp(k+1, value)
    return memo[k][value]
print(dp(0, 0)-1)