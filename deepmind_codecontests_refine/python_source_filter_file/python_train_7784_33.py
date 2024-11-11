n, m = map(int, input().split())
if n%2 == 1:
  for i in range(m):
    print(m-i, m+1+i)
else:
  for i in range(m):
    if 4*(i+1) > n:
      print(m-1, m+2+i)
    else:
      pritn(m-1, m+1+i)