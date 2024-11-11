M = int(input())
D = C = 0
for i in range(M):
  d, c = map(int, input().split())
  D += d
  C += c
print(C - 1 + (D - 1) // 9)
