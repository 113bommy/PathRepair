A,B = map(int,input().split())

if max(A,B)<=9:
  print(A*B)
else:
  print(-1)