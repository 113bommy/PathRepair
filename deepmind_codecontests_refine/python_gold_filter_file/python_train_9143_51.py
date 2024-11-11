A,B,C,D=map(int,input().split())
p=min(B,D)-max(A,C)
if p<=0:
  print(0)
else:
  print(p)