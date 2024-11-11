N = int(input()) == len(set(map(int, input().split())))
if N:
  print("Yes")
else:
  print("No")