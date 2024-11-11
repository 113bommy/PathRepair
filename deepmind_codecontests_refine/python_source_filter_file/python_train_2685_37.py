from fractions import gcd
from functools import reduce


def lcm_base(x,y):
    return (x*y)//gcd(x,y)


def lcm(A):
    return reduce(lcm_base,A,1)


n,m=map(int,input().split())
A=list(map(int,input().split()))
num=lcm(A)
semi=num//2

ans=0
if any([True for i in range(n) if num%A[i]==0]):
    print(0)
elif semi<=m:
    ans +=1
    m -=semi
    ans +=m//num
    print(ans)
else:print(0)