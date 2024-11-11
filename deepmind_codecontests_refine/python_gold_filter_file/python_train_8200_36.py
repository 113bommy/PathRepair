N = input()
A = input().split()
if int(N) == len(set(A)):
  print("YES")
else:
  print("NO")