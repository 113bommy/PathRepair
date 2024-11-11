x, a, b = map(int, input().split())
if abs(a-x) < abs(b-a):
  print("A")
else:
  print("B")