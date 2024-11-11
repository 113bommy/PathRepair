
n,m = map(int, input().split())

l = [-1]*m
r = [-1]*m
for i in range(m):
  l[i], r[i] = map(int, input().split())


ret = min(r)-max(l)+1
print(ret)