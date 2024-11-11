n, k = map(int, input().split())
t = {}
for i in map(int, input().split()): t[i] = t.get(i, 0) + 1
t = list(t.items())
t.sort()
t.reverse()
d = s = 0
for i, j in t:
    if j > d:
        s += (i - 1) * ((j - d - 1) // k + 1)
        d = -j % k
    else: d -= j
print(2 * s)