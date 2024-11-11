N = int(input())
A = input()

if len(A) > N:
  print(A[:N]+"...")
else:
  print(A)