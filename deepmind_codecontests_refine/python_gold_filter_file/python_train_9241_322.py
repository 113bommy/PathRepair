K=int(input())
S=input()
a=len(S)
if a<=K:
  print(S)
else:
  print(S[:K]+'...')