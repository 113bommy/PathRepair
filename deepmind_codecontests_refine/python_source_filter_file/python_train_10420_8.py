import sys
from collections import Counter

n, x = map(int, input().split())
arr = list(map(int, input().split()))
arr2 = list(map(lambda a: a & x, arr))
sa = Counter(arr)
sa2 = Counter(arr2)

for i in arr:
    if sa[i] >= 2:
        print(0)
        sys.exit(0)
for i in arr:
    if (sa2[i] >= 2 if (i & x == i) else i in sa):
        print(1)
        sys.exit(0)
for i in sa2:
    if sa2[i] >= 2:
        print(2)
        sys.exit(0)
print(-1)