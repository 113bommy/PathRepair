A,B,C = map(int,input().split())
if A < C < B or B < C < A:
  print("YES")
else:
  print("No")