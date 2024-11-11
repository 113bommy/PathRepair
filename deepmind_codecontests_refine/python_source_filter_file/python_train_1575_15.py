import math
n, m, k = map(int, input().split())
mod = 998244353
f = math.factorial(n-1)/(math.factorial(k)*math.factorial(n-k-1))
f*=m
f*=(m-1)**k
f%=mod
print(int(f))