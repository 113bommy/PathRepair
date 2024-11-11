n, m = map(int, input().split())

lb = 1
ub = n

for _ in range(m):
  a, b = map(int, input().split())
  if a>b: a,b=b,a
  lb = max(lb, a)
  ub = min(ub, b)

print(max(0, ub-lb))