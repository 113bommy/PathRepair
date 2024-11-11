N = int(input()) == len(set(map(int, input().split())))
if N:
  print("YES")
else:
  print("NO")