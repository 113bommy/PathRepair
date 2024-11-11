n,m = tuple(map(int,input().split()))

if n-m*2<=0:
  rest = m-n*2
  print(n+rest//4)
else:
  print(m//2)
  