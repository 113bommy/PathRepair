n,m=map(int,input().split())
j = 0
if n % 2 == 1:
  for i in range(m):
    print(1+i, n-i-j)
else:
  for i in range(m):
    if 2*((n-i) - (1+i)) - n >= 2:
      print(1+i, n-i-j)
    else:
      j = 1
      print(1+i, n-i-j)