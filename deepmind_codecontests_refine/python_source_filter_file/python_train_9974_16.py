n=int(input())
A=list(map(int,input().split()))

L,R=[0]*n,[0]*n
L[0],R[-1]=A[0],A[-1]

from math import gcd

for i in range(1,n):
    L[i]=gcd(A[i],L[i-1])
for i in range(n-2,-1,-1):
    R[i]=gcd(A[i],R[i+1])

ans=max([L[-2],R[1]]+[gcd(L[i-1],R[i+1])for i in range(1,n-1)])
print(ans)