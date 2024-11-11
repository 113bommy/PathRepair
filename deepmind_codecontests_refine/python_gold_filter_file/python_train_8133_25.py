n,k=map(int,input().split())
if k<=n/2:
    print(n*3+k-1)
else:
    print(n*3+n-k)
