from collections import Counter

h, w = map(int, input().split())
a = []
for _ in range(h):
    aa = list(input())
    a += aa

c = Counter(a)

hq, hr = divmod(h, 2)
wq, wr = divmod(w, 2)
d = {1: hr * wr,
     2: hq * wr + hr * wq,
     4: hq * wq}

for v in c.values():
    q4, r4 = divmod(v, 4)
    if q4 > d[4]:
        r4 += 2 * (q4 - d[4])
        q4 = d[4]
    d[4] -= q4
    q2, r2 = divmod(r4, 2)
    d[2] -= q2
    d[1] -= r2

if any(d.values()):
    ans = "No"
else:
    ans = "Yes"

print(ans)
