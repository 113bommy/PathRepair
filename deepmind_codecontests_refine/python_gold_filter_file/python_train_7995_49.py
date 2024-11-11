n,m = map(int,input().split())
x = sorted(list(map(int,input().split())))
x_d = sorted([x[i+1]-x[i] for i in range(m-1)])
print(sum(x_d[:max(m-n,0)]))