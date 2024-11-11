import sys
fin = sys.stdin

n = int(fin.readline())
b = fin.readline()
m = len(b)

res = 0
for i in range(n, m, n):
  if b[i - 3] == b[i - 2] == b[i - 1]:
    res += 1

print(res)