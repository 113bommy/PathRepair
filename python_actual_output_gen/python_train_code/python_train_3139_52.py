A,B,C,D=map(int,input().split())
p=min(C,D)-max(A,B)
if p<=0:
  print(0)
else:
  print(p)