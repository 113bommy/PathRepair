import collections
import sys
import resource
sys.setrecursionlimit(200000)

n, m = map(int, input().split(' '))

f = [x for x in range(n)]

def find(x):
  if f[x] == x:
    return x
  root = find(f[x])
  f[x] = root
  return root

for i in range(m):
  a, b = map(int, input().split(' '))
  a -= 1
  b -= 1
  if find(a) != find(b):
    f[find(a)] = find(b)

for i in range(n):
  find(i)
  
print(max(collections.Counter(f).values()))