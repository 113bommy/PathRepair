N, A, B, C, D = map(int, input().split())
S = input()
A, B, C, D = A-1, B-1, C-1, D-1
if C < D:
  if "##" in S[A:D]:
    print("No")
  else:
    print("Yes")
else:
  if "##" in S[A:C]:
    print("No")
  elif "..." in S[B:D]:
    print("Yes")
  else:
    print("No")
