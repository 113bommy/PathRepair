n,k=map(int,input().split())

x=map(int,input().split())


if n<k:
    print(-1)
else:
    x=list(reversed(sorted(x)))
    print(x[k-1])









