x, y = map(int, input().split())
if y > x*4 or y < x*2 or y&2 == 1:
  print("No")
else:
  print("Yes")