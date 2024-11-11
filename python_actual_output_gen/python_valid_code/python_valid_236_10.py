t = int(input())
for _ in range(t):
  n, a, b = map(int, input().split())
  print(max(a+b-n+1, 1), min(a+b-1, n))