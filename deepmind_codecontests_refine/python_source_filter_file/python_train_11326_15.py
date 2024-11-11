h, w, a, b = map(int, input().split())
for _ in range(h-b):
  print("1"*(w-a) + "0"*a)
for _ in range(b):
  print("0"*(w-a) + "0"*a)