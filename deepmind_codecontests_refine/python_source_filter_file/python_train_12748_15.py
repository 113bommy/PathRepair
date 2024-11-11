n = int(input())
prev = 1
for i in range(1, n):
  prev = (prev + i) % n
  print(prev, end=' ')