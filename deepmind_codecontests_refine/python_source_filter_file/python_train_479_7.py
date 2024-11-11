import sys
from collections import defaultdict
n = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().strip().split()))


psum = 0
counter = defaultdict(int)
result = 0
for i in range(n):
  counter[a[i]] += 1
  psum += a[i]
  result += (i + 1) * a[i] - psum
  result += counter[a[i] - 1] - counter[a[i] + 1]
print(result)
