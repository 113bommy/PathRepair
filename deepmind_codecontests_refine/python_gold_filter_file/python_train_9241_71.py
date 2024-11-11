K=int(input())
A=input()
if len(A)<=K:
  print(A)
else:
  print(A[:K]+"...")