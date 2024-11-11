N=int(input())
from functools import reduce
size=int(N**.5+(1-1e-9))
a=[0]*N
b=[0]*size
f=lambda v: reduce(lambda x,y:x|y,v,0)
def init(v):
    a=v
    b=[f(a[j*size:(j+1)*size]) for j in range(size)]
    return a,b
def update(i,v):
    a[i]=v
    j=i//size
    b[j]=f(a[j*size:(j+1)*size])
def r_query(l,r):
    L,R=0--l//size,r//size
    if L>=R:
        return f(a[l:r])
    else:
        return f(a[l:L*size]+b[L:R]+a[R*size:r])
def c(n):
    r=0
    while n:
        r+=n&1
        n>>=1
    return r

o=lambda c:ord(c)-ord('a')
bit=[2**i for i in range(26)]
S=input()
Q=int(input())
XYZ=[input().split() for i in range(Q)]
a,b=init([bit[o(c)] for c in S])
for x,y,z in XYZ:
    if x=='1':
        update(int(y)-1,bit[o(z)])
    else:
        print(c(r_query(int(y)-1,int(z))))