n = int(input())
a = list(map(int, input().split()))

x = 0
y = 0
z = 0
for i in a:
  if i%4 == 0: x += 1
  elif i == 2: y = 1
  else: z += 1

if y+z-1 <= x: print("Yes")
else: print("No")