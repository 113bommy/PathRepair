n,k=[int(x) for x in input().split()]
a=[int(x) for x in input().split()]
a.sort()
if k>a[n-1]:
    print(-1)
else:
    print(a[n-k],1)