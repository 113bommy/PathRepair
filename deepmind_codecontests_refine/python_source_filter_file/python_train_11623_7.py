a, b, c, m = map(int, input().split())
if 2*m+2>2*a or 2*m+1>2*b or m>=2*c or 2*m<=c:
  print(-1)
  exit()
if 2*m+2<=a:
  print(a)
else:
  print(2*m+2)

if 2*m+1<=b:
  print(b)
else:
  print(2*m+1)

if m>=c:
  print(m)
else:
  print(c)
