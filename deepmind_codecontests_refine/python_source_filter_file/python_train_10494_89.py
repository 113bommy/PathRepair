N, A, B, C, D = map(int, input().split())
S = input()
A, B, C, D = A-1, B-1, C-1, D-1
if C < D:
  if "##" in S[A:D+1]:
    print("No")
  else:
    print("Yes")
else:
  if "##" in S[A:C+1]:
    print("No")
  elif "..." in S[B:D+2]:
    print("Yes")
  else:
    print("No")
