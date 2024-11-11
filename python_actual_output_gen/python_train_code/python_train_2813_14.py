N = input()
A = input().split()
if int(N) == len(set(A)):
  print("NO")
else:
  print("YES")