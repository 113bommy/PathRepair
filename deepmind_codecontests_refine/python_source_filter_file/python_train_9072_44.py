from math import ceil

n = int(input())
m = int(ceil((n + 1)/2))
for i in range(m):
    print(1, i + 1)
for i in range(n - m):
    print(i + 2, m)