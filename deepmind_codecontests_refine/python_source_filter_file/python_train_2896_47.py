from collections import defaultdict
from itertools import accumulate
n, k = map(int, input().split())
A = list(map(int, input().split()))
Acum = [0]
Acum.extend(accumulate(A))
cnt = defaultdict(int)
for i in range(n):
    for j in range(i+1, n+1):
        beauty = Acum[j]-Acum[i]
        cnt[beauty] += 1

x = 0
for t in reversed(range(41)):
    y = 1 << t
    cnt_k = 0
    for beauty, c in cnt.items():
        if (x+y) & beauty == (x+y):
            cnt_k += c
    if k <= cnt_k:
        x += y

print(x)