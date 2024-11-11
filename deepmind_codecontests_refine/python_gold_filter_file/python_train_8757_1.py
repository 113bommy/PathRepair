s, l, k, r, rend, sp, lk, f = '', -1, 0, {}, {}, [], 0, 1
d1 = d2 = 0
n = int(input())
a = tuple(map(int, input().split()))
for key, val in enumerate(a):
    if r.get(val) is None:
        r[val] = key
    else:
        rend[val] = key
for key, value in rend.items():
    sp.append([r.get(key), value])
sp.sort(key=lambda x: x[0])
if sp:
    d1, d2 = sp[0][0], sp[0][1]
for i in sp[1:]:
    if i[0] < d2 < i[1]:
        d2 = i[1]
    elif i[0] > d2:
        k += (d2 - d1 + 1)
        lk += 1
        d1 = i[0]
        d2 = i[1]
k += (d2 - d1 + 1)
for i in range(n - k + lk):
    f *= 2
    if f > 998244353:
        f += -998244353
print(f)


