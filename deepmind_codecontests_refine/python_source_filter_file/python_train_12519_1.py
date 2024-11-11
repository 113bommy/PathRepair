from sys import stdin, stdout
from collections import Counter, defaultdict
import heapq

t = int(stdin.readline())
for _ in range(t):
    n, x, y = map(int, stdin.readline().split())
    a = list(map(int, stdin.readline().split()))

    unused = set(list(range(1, n+2))) - set(a)
    r = list(unused)[0]
    ans = [r]*n

    c = Counter(a)
    h = []
    ilist = defaultdict(list)
    for i, k in enumerate(a):
        ilist[k].append(i)
    for k in c:
        v = c[k]
        heapq.heappush(h, (-v, k))

    for _ in range(x):
        v, k = heapq.heappop(h)
        idx = ilist[k].pop()
        ans[idx] = k
        if v+1 < 0:
            heapq.heappush(h, (v+1, k))

    todo = y-x
    while todo > 0:
        v1, k1 = heapq.heappop(h)
        idx1 = ilist[k1].pop()
        if not h:
            if todo == 1:
                for i in range(n):
                    if ans[i] != r and ans[i] != a[i] and ans[i] != k1:
                        ans[i], ans[idx1] = k1, ans[i]
                        if ans[i] == a[i] or ans[idx1] == a[idx1]:
                            ans[i], ans[idx1] = k1, ans[i]
                            continue
                        todo -= 1
                        break
            break
        v2, k2 = heapq.heappop(h)
        idx2 = ilist[k2].pop()
        if todo > 1:
            ans[idx1], ans[idx2] = k2, k1
            if v1+1 < 0:
                heapq.heappush(h, (v1+1, k1))
            if v2+1 < 0:
                heapq.heappush(h, (v2+1, k2))
            todo -= 2
        else:
            ans[idx1] = k2
            todo -= 1
    if todo > 0:
        print("NO")
        continue
    
    print("YES")
    print(" ".join(map(str, ans)))
