x = int(input())
x += 1
while True:
  xs = [i for i in range(1, x + 1) if x % i == 0]
  if len(xs) == 2:
    break
  x += 1
print(x)
