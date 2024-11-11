import math
def c(n,r):
    return math.factorial(n) // (math.factorial(n - r) * math.factorial(r))
 
n,k=map(int,input().split())
mod=10**9+7
 
for i in range(k):
    if n-k<i:
        print(0)
    else:
        print(c(k-1,i)*c(n-k+1,i+1)%mod)