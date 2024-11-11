# from math import *
n = int(input())
mod = 1e9+7
a = 1
for i in range(1,n+1):
    a = a*i
    a %= mod
    # a = int(a)
    # print(a)
a%=mod
# a = int(a)

b = 1
for i in range(n-1):
    b *= 2
    b %= mod
    # b = int(a)
b %= mod
# b = int(b)
ans = a - b + mod
print(a,b,ans)
# print (ceil(lgamma(n+1)/log(10)))
ans %= mod
print(int(ans))
