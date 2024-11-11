import sys

c, d = map(int, sys.stdin.readline().split())
n, m = map(int, sys.stdin.readline().split())
k = int(sys.stdin.readline())

total = n * m - k
if total <= 0:
  print(0)
  sys.exit(0)

a = [d*i for i in range(0, total+1)]

for i in range(1, total+1):
  if i <= n:
    if a[i] > c:
      a[i] = c
  else:
    if a[i-n] + c < a[i]:
      a[i] = a[i-n] + c

print( a[total] )