
def union(x, y, t):
    x, t_x = findSet(x)
    y, t_y = findSet(y)
    link(x, t_x, y, t_y, t)


def link(x, d_x, y, d_y, t):
    print('', 'x', 'y')
    print('', x, y)
    print('', d_x, d_y, t)
    if r[x] > r[y]:
        p[y] = x
        d[y] = d_x + d_y - t
        print('', y, '->', p[y], '=', d[y], '\n')

    else:
        p[x] = y
        d[x] = d_y - d_x + t
        if r[x] == r[y]: r[y] = r[y] + 1
        print('', x, '->', p[x], '=', d[x], '\n')


def findSet(x):
    if x != p[x]:
        p[x], t = findSet(p[x])
        d[x] += t
    return p[x], d[x]


def diff(x, y):
    x, d_x = findSet(x)
    y, d_y = findSet(y)
    if x == y:
        return d_x - d_y

    else:
        return '?'




if __name__ == '__main__':

    p, r, d = [], [], []

    n_set, n_quare = map(int, input().split())

    for i in range(n_set):
        p.append(i)
        r.append(0)
        d.append(0)


    for i in range(n_quare):
        l = input().split()

        if len(l) == 4:
            _, x, y, t = map(int, l)
            union(x, y, t)

        else:
            _, x, y = map(int, l)
            print(diff(x, y))

