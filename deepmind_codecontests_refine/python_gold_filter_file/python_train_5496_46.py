M = int(input())

d_sum = 0
c_sum = 0

for i in range(M):
  d, c = [int(_) for _ in input().split()]
  d_sum += d * c
  c_sum += c

print(c_sum - 1 + (d_sum - 1) // 9)