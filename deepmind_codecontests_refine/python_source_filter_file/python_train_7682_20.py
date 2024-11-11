n,m,k=map(int,input().split())
mod=10**9+7
import math
def f(x):
  return math.factorial(x)
def c(x,y):
  return f(x)//(f(x-y)*f(y))

ans=(n**2*(m-1)*m*(m+1)//6)%mod
ans=(ans+m**2*(n-1)*n*(n+1)//6)%mod
ans=(ans*c(m*n-2,k-2))%mod
print(ans)