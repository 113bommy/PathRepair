A, B = map(int,input().split())
S = input()

if(S[A] == "-" and S.count("-") < 2):
  print("Yes")
else:
  print("No")
