A,B = map(int,input().split())
S = list(input())
if S[A] == "-" and S.count("-") == 1:
  print("Yes")
else:
  print("No")
