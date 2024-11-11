import sys
I=lambda:list(map(int,input().split()))
n,k=I()
if k==1 or k==n:
    print(2*n+n)
else:
    print(3*n+(abs(n-k)))