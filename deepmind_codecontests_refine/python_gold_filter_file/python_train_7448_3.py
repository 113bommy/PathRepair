n, m, c = input().split()
n, m = map(int, [n, m])
R = []
for i in range(n):
    R.append(list(input()))


def f(_y, _x):
    s = set()

    if 0 < _x < m - 1:
        s = {R[_y][_x - 1], R[_y][_x + 1]}
    elif m == 1:
        s = {R[_x][0]}
    elif _x == 0:
        s = {R[_y][0], R[_y][_x + 1]}
    elif _x < m:
        s = {R[_y][-2], R[_y][-1]}

    if 0 < _y < n - 1:
        s.add(R[_y - 1][_x])
        s.add(R[_y + 1][_x])
    elif n == 1:
        s.add(R[0][_x])
    elif _y == 0:
        s.add(R[0][_x])
        s.add(R[_y + 1][_x])
    elif _y < n:
        s.add(R[-2][_x])
        s.add(R[-1][_x])

    return s


z = set()
for y in range(n):
    for x in range(m):
        if c in f(y, x):
            z.add(R[y][x])
z.discard(".")
z.discard(c)
print(len(z))
