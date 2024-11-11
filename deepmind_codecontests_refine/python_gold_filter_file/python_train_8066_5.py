n = int(input())
#coord, apples
e = []
for i in range(n):
    c, a = map(int, input().split())
    e.append((c, a))
e.sort(key=lambda x: x[0])
rev = list(reversed(e))
l, m, res = 0, 0, 0
for el in e:
    if el[0] < 0:
        l += 1
    else:
        m += 1
if l < m:
    lc, mc = 0, 0
    for el in e:
        if mc == l + 1:
            break
        if el[0] > 0:
            res += el[1]
            mc += 1
    for el in rev:
        if lc == l:
            break
        if el[0] < 0:
            res += el[1]
            lc += 1
else:
    lc, mc = 0, 0
    for el in e:
        if mc == m:
            break
        if el[0] > 0:
            res += el[1]
            mc += 1
    for el in rev:
        if lc == m + 1:
            break
        if el[0] < 0:
            res += el[1]
            lc += 1
print(res)