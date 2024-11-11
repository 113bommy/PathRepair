from math import ceil, floor, gcd, fabs, factorial, fmod, sqrt, inf
import math
def sp(): return map(int, input().split())
def fun(x):
    return sum(int(i) for i in str(x))
# t=int(input())
t=1
for _ in range(t):
    d=998244353
    w,h=sp()
    ans=pow(w,2)*pow(h,2)
    print(ans%d)