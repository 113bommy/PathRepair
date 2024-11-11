d = [[0] * 10 for i in range(10)]

def b(x, y):
    for i in range(x - 2, x + 3):
        a = 3 - abs(x - i)
        for a in range(y - a + 1, y + a):
            if 0 <= i < 10 and 0 <= a < 10:
                d[a][i] += 1


def m(x, y):
    for i in range(x - 1, x + 2):
        for j in range(y - 1, y + 2):
            if 0 <= i < 10 and 0 <= j < 10:
                d[j][i] += 1


def s(x, y):
    r = (1, 0)
    for i in range(x - 1, x + 2):
        a = abs(x - i)
        for j in range(y - r[a], y + r[a] + 1):
            if 0 <= i < 10 and 0 <= j < 10:
                d[j][i] += 1

while 1:
    try:
        f = (None, s, m, b)
        x, y, size = list(map(int, input().split(',')))
        f[size](x, y)

    except:
        break


r1 = r2 = 0
for i in range(10):
    for j in range(10):
        r1 += 1 if d[i][j] == 0 else 0
        r2 = max(r2, d[i][j])

print(r1, r2)