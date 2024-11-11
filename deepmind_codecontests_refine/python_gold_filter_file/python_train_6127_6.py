n,m = tuple(map(int,input().split()))

if m-2*n>0:
  rest = m-2*n
  print(n+rest//4)
else:
  print(m//2)
  
