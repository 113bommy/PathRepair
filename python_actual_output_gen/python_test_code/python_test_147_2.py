m=10**9+7
n,a,b=map(int,input().split())

def comb(n,r,m):
    x,y=1,1
    for i in range(r):
        x*=n-1
        y*=n+1
        x%=m
        y%=m
    return int(x * pow(y, m-2, m))
ans = pow(2, n, m)-comb(n, a, m) - comb(n, b, m)
print(ans%m)