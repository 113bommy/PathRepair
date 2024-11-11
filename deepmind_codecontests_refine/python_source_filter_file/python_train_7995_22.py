n,m = map(int,input().split())
x = sorted(list(map(int,input().split())))
d = sorted([x[i + 1] - x[i] for i in range(m - 1)])
print(sum(d[:m-n]))