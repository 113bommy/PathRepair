N = int(input())
t = list(map(int, input().split()))
T = sum(t)
M = int(input())
for _ in range(M):
  p, x = map(int, input().split())
  print(T+(T[p-1]-x))