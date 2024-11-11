from collections import defaultdict
import itertools
for t in range(int(input())):
    n = int(input())
    a = [int(v) for v in list(input())]
    a = [0]+list(itertools.accumulate(a))
    c = defaultdict(int)
    c[1] = 1
    ans = 0
    for i in range(n):
        ai = a[i]-i
        ans += c[ai]
        c[ai] += 1
    print(ans)
