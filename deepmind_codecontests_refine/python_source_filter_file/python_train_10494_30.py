N,A,B,C,D = map(int,input().split())
S = str(input())
E = max(C,D)
AE = S[A:E]
BD = S[B-2:D+1]
if "##" in AE:
  print("NO")
elif C > D and "..." not in BD:
  print("NO")
else:
  print("YES")