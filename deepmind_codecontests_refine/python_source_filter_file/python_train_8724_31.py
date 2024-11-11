n,m=map(int,input().split())
c = [0]*m
for i in range(n):
  a = list(map(int, input().split()))
  for e in a:
    c[e-1] += 1
print(c.count(n))