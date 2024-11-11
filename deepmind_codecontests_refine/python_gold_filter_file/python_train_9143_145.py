A,B,C,D=map(int,input().split())
s=max(A,C)
e=min(B,D)
if s<e:
  print(e-s)
else:
  print(0)