N = int(input())
SUM = 0
map = [0] * 100001
for i in [int(i) for i in input().split()]:
  SUM += i
  map[i] += 1

Q = int(input())
for i in range(Q):
  [b,c] = [int(i) for i in input().split()]
  SUM += (c-b)*map[b]
  print(SUM)
  map[c] += map[b]
  map[b] = 0