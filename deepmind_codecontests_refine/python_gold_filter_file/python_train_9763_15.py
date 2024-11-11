a,b,c,k=(int(x) for x in input().split())
if a+b >= k:
  print(min(k,a))
else:
  print(a-k+a+b)
