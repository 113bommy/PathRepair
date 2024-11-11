import math
f=math.factorial
n,m,k=map(int,input().split())
mod = 998244353
ret=f(n-1)//(f(k)*f(n-1-k))*m*((m-1)**k%mod)
print(ret)