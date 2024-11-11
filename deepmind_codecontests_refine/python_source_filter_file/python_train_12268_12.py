from collections import defaultdict

N = int(input())
D = list(map(int, input().split()))
kind = defaultdict(int)
for d in D:
  kind[d] += 1

M = int(input())
T = list(map(int, input().split()))
for t in T:
  d[t] -= 1
  if d[t] < 0:
    print('NO')
    quit()

print('YES')