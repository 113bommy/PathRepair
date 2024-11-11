import sys
from collections import Counter
n = int(input())
a = list(map(int, input().split()))
m = 0
d = Counter(a)
for i in range(d[0]):
    j = 0
    k = 0
    while k != i:
        if a[j] == 0:
            k += 1
        j += 1
    while j < n:
        if a[j] == 1:
            k += 1
        j += 1
    m = max(m,k)
print(m)
