n, m, k, x, y = map(int, input().split())

ans = [[0] * m for x in range(n)]

onebig = (2*n-2)*m or m

oo = k // onebig

for i in range(n):
    for j in range(m):
        if i == 0 or i == n-1:
            ans[i][j] += oo
            k -= oo
        else:
            ans[i][j] += 2*oo
            k -= 2*oo

from itertools import chain

for i in chain(range(n), range(n-1, 0, -1)):
    if not k:
        break
    for j in range(m):
        if not k:
            break
        ans[i][j] += 1
        k -= 1

_max = max(list(map(max, ans)))
_min = min(list(map(min, ans)))
_ans = ans[x-1][y-1]


print(_max, _min, _ans)
