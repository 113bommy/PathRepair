M = int(input())
CD = C = 0
for i in range(M):
  d, c = map(int, input().split())
  CD += c * d
  C += c
print(C - 1 + (CD - 1) // 9)
