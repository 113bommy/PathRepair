n,k=map(int,input().split())
if k<=n/2:
    x=k
else:
    x=n-k+1
if n==2:
    print(str(6))
else:
    print(3*n+x-1)