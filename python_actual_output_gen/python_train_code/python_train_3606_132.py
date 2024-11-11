N,A,B,C,D = map(int,input().split())
S = input()

if "##" in S[A-1:C] or "##" in S[B-1:D]:
  print("No")
elif C < D:
  print("Yes")
else:
  if "..." in S[B-2:D+2]:
    print("Yes")
  else:
    print("No")