n,m=map(int,input().split())
c = [0]*m
for i in range(n):
  a = list(map(int, input().split()))
  for e in a[1:]:
    c[e-1] += 1
print(c.count(n))
