N, M=map(int, input().split())
X=sorted(list(map(int, input().split())))
d=sorted([X[i]-X[i-1] for i in range(1, M)])
if N>=M:
  print(0)
else:
  print(int(sum(d[:-N+1])))