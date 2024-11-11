from bisect import bisect_right
a, b, c = input(), input(), 'abcdefghijklmnopqrstuvwxyz'
p = {i: [] for i in c}
for i, j in enumerate(a): p[j].append(i)
if any(j in b and not p[j] for j in c): print(-1)
else:
    k, s = -1, 1
    for j in b:
        q = p[j]
        if k < q[-1]: k = q[bisect_right(q, k)]
        else: k, s = q[0], s + 1
    print(s)