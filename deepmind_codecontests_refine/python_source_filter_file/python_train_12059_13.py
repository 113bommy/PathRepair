N,M = map(int,input().split())

n = min(N,M)
m = max(N,M)

if n*m == 1:
  print(1)
if n == 1:
  print(m-2)
  exit()
print((n-2)*(m-2))
