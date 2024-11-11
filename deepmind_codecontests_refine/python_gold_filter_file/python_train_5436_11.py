from math import factorial as fact

def C(n,r):
    return fact(n)//(fact(r)*fact(n-r))

n, m = map(int, input().split())
mod = 10**9 + 7
print(C(2*m+n-1, n-1)%mod)