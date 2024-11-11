n,k=[int(x) for x in input().split()]
if k>(n+n-1):
    print(0)
    exit()
if k==n+n-1:
    print(1)
    exit()
if k<=n:
    print((k-1)//2)
    exit()
print((2*n-k+1)//2)