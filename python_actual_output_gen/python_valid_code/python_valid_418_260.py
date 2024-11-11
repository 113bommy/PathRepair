A,B = map(int,input().split())
if round(B%A) == 0:
  print(A + B)
else:
  print(A-B)