A,B,C = map(int,input().split())
if A < B < C or C < B < A:
  print("YES")
else:
  print("No")