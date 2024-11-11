import math
fac = math.factorial
n = int(input())
def nCr(n,k):
        return fac(n)//(fac(n-k)*fac(k))

t = nCr(5+n-1,5)*nCr(3+n-1,3)

print((t))
