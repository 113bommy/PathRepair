from math import ceil
n, k = map(int, input().split())
s = set()
for d in range(1, ceil(n ** .5) + 1):
    if n % d == 0:
        s.add(d)
        if d ** 2 != n:
            s.add(n // d)
if k > len(s):
    print(-1)
else:
    for i, elem in enumerate(s):
        if i + 1 == k:
            print(elem)
            break
