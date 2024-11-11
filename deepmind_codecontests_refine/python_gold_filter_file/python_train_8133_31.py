n, k = map(int, input().split())
if k==n or k==1:
    print(n*3)
else:
    print(n*3+min(k-1,n-k))
