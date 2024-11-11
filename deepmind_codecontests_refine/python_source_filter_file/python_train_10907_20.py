x,k,d = map(int,input().split())
if abs(x) >= k*d:
  print(abs(x)-k*d)
  exit()
x = abs(x)
r = x%d
if (x-r)%2 == k%2:
  print(r)
else:
  print(abs(r-k))