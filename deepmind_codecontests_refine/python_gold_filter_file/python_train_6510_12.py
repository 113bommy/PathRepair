read = lambda: map(int, input().split())
n = int(input())
a = list(read())
m = int(input())
b = list(read())
c = list(read())
from collections import Counter as C
d = C()
for i in a: d[i] += 1
mb = mc = ind = -1
for i in range(m):
    if d[b[i]] > mb:
        mb = d[b[i]]
        mc = d[c[i]]
        ind = i + 1
    elif d[b[i]] == mb and d[c[i]] > mc:
        mc = d[c[i]]
        ind = i + 1
print(ind)
