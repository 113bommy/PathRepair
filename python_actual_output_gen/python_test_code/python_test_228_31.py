t = int(input())
for _ in range(t):
  a, b = map(int, input().split())
  print(abs(a - b) / 10 + (1 if a - b else 0))