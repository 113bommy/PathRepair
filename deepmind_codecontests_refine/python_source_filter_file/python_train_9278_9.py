import sys,math
input=sys.stdin.readline
L=lambda : list(map(int,input().split()))
M=lambda : map(int,input().split())
n=int(input())
if(n==1):
    print(2)
else:
    k=int(math.sqrt(n))
    m=k
    k=k*k+1
    if(m**2==n):
        print(2*m)
    else:
        if(n<=k):
            print(2*m+1)
        else:
            print(2*(m+1))
