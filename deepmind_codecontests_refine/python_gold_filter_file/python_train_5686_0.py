n = int(input())


def conflicts(a, b):
    return a[1] >= b[0]


shows = []
for i in range(n):
    x, y = map(int, input().split())
    shows.append((x, y))
shows.sort(key=lambda x: x[0])

ok = True
tv1 = [(-1, -1)]
tv2 = [(-1, -1)]
for s in shows:
    if not conflicts(tv1[-1], s):
        tv1.append(s)
    elif not conflicts(tv2[-1], s):
        tv2.append(s)
    else:
        ok = False
        break

if ok:
    print('YES')
else:
    print('NO')
