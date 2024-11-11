S = list(input())
M = len(S) // 2
if S == S[::-1] and S[:M] == S[:M:-1]:
  print("Yes")
else:
  print("No")
