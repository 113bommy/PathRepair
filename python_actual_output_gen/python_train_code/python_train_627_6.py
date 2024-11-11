import sys
n = int(sys.stdin.readline())
m = map(int, sys.stdin.read().split())
ab = list(zip(m, m))
res = 0
for i, j in ab[::-1]:
  if j != 1:
  	res += j - (i + res) % j
print(res)