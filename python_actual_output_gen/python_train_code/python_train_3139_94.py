A,B,C,D=map(int,input().split())
s=max(A,B)
e=min(C,D)
if s<e:
  print(e-s)
else:
  print(0)