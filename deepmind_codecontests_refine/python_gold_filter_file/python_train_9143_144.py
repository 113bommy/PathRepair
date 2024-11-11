A,B,C,D=map(int,input().split())
X=min(B,D)-max(A,C)
if X > 0:
  print(X)
else:
  print(0)