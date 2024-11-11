def check(bound):
  more, less = 0, 0
  for x in a:
    if x > bound: more += x - bound
    else: less += bound - x
  return more * (100 - k) / 100 - less >= 0

n,  k = map(int, input().split())
a = [int(x) for x in input().split()]

res, l, r = 0, 0, 1000
if max(a) == min(a): res = a[0]
for loops in range(200):
  m = (l + r) / 2
  if check(m):
    res = m; l = m
  else: r = m
  
print(f'{res:.8f}')