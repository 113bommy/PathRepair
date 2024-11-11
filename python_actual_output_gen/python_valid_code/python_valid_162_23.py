import sys
from functools import reduce
input = sys.stdin.readline

def readPair():
  return tuple(map(int, input().split()))

def readEntry():
  e = readPair()
  return (e[0], e[1], e[0] - e[1])

(n, m) = readPair()
entries = [readEntry() for _ in range(0, n)]

entries.sort(key=lambda x: x[2], reverse=True)

size = reduce(lambda s, e: s + e[0], entries, 0)
count = 0

while (size > m and count < n):
  size -= entries[count][2]
  count += 1

print(-1 if count >= n else count)