A,B = map(int,input().split())
if round(A % B) == 0:
  print(A + B)
else:
  print(A-B)
  