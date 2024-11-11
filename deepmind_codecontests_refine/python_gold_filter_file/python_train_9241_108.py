K=int(input())
S=input()

if len(S)>K:
  print(S[:K]+"...")
else:
  print(S[:])
  