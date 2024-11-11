n,k = map(int,input().split())
a = sorted(list(map(int,input().split())))
if k>n:
    print(-1)
else:
    print(a[k],0)
