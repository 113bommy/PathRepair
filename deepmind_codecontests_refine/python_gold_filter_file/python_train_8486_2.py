import re, sys, string, operator, functools, fractions, collections
sys.setrecursionlimit(10**7)
dX= [-1, 1, 0, 0,-1, 1,-1, 1]
dY= [ 0, 0,-1, 1, 1,-1,-1, 1]
RI=lambda x=' ': list(map(int,input().split(x)))
RS=lambda x=' ': input().rstrip().split(x)
mod=int(1e9+7)
eps=1e-6
#################################################
n,k=RI()
l=1
r=n*(k-1)+1
print((n*(2*r+((n-k+1)*(n-1))))//2)
for i in range(n):
    for j in range(n):
        if j+1>=k:
            print(r,end=" ")
            r+=1
        else:
            print(l, end=" ")
            l+=1
    print()




