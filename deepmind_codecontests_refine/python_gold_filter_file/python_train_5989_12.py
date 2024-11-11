def fact(n, acc = 1):
  if n == 0:
    return acc
  return fact(n - 1, n * acc)

def ncr(n):
  return fact(n) / (fact(n - 2) * 2)


n = int(input())
r = [0] * n
c = [0] * n

import sys

i = 0
for line in sys.stdin:
    j = 0
    for letter in line:
        if letter == 'C':
            r[i] += 1
            c[j] += 1
        j += 1
    i += 1
    
ans = 0
for i in range(n):
    if r[i] > 1:
        ans += ncr(r[i])
    if c[i] > 1:
        ans += ncr(c[i])

print(int(ans))