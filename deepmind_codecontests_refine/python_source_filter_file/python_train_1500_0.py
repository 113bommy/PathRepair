n = eval(input())

area = 0
p1, p2 = [], []
for i in range(n):
    in_ = input().split()
    p1.append(tuple(map(int, in_[0:2])))
    p2.append(tuple(map(int, in_[2:4])))
    area += (p2[i][0] - p1[i][0]) * (p2[i][1] - p1[i][1])
pl = min(p1)
pu = max(p2)
ok = True
for p in p1 + p2:
    if pl[1] > p[1]:
        ok = False
    if pu[1] < p[1]:
        ok = False

w, h = (pu[0] - pl[0]),  (pu[1] - pl[1])
exp = w * h
print('YES' if w == h and area == exp else 'NO')
