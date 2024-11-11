k,a,b = map(int,input().split())
if a >= b+2:
  print(k+1)
else:
  d = k-(a-1)
  e = a
  e += (b-a)*(d//2)
  e += d%2
  print(e)