N = int(input())
T = list(map(int, input().split()))
M = int(input())

s = sum(T)
for i in range(N):
  P, X = map(int, input().split())
  print(s - T[P-1] + X)