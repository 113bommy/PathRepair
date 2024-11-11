from collections import Counter
n, m = map(int, input().split())
cp = []
for i in range(m):
    cp.append(list(map(int, input().split())))
v1, v2 = cp[0][0], cp[0][1]
m1, m2 = [], []
for i in range(1, m):
    if v1 not in cp[i]:
        m1.append(cp[i])
    if v2 not in cp[i]:
        m2.append(cp[i])
used = [[], [], [], []]
if (len(m1) < 2) | (len(m2) < 2):
    print('YES')
else:
    v1, v2 = m1[0][0], m1[0][1]
    for i in range(1, len(m1)):
        if v1 not in m1[i]:
            used[0].append(0)
        else:
            used[0].append(1)
        if v2 not in m1[i]:
            used[1].append(0)
        else:
            used[1].append(1)

    v1, v2 = m2[0][0], m2[0][1]
    for i in range(1, len(m2)):
        if v1 not in m2[i]:
            used[2].append(0)
        else:
            used[2].append(1)
        if v2 not in m2[i]:
            used[3].append(0)
        else:
            used[3].append(1)
    b = False
    for i in range(4):
        if len(Counter(used[i])) <= 1:
            b = True
            break
    if b:
        print('YES')
    else:
        print('NO')
