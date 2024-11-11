from fractions import gcd
N=int(input())
A=list(map(int,input().split(' ')))
L = 1
def lcm(x,y):
    return x//gcd(x,y)*y
for a in A:
    L = lcm(L,a)
ans=0
for a in A: ans+=L//a
print(ans%(10**9+7))