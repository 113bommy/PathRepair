import sys

# sys.stdin = open('c2.in')
# sys.stdin = open('gen_c/c10.in')


def solve_it_large(n, l, t, x, w):
    ants = []
    for i in range(n):
        ants.append([x[i], w[i], (x[i] + w[i] * t) % l, i])
    # ants.sort()

    n_intersections = 0
    x0, w0, dest0, i0 = ants[0]
    for x, w, dest, i in ants:
        if w != w0:
            d = (w0 * (x - x0) + l) % l
            intersections = 0
            if 2 * t >= d:
                intersections = (2 * t - d) // l + 1
            n_intersections += intersections

    res = [0] * n
    shift = n_intersections
    for i in range(n):
        res[ants[(i + w0 * shift) % n][3]] = ants[i][2]
    return res


def solve_it_chameleons(n, l, t, x, w):
    initial_color = [i for i in range(n)]

    chameleons = [[x[i], w[i], initial_color[i]] for i in range(n)]
    initial_color_clockwise = [chameleons[i][2] for i in range(n)]

    x0, w0, color0 = chameleons[0]
    for i in range(n):
        if w[i] != w0:
            d = (w0 * (x[i] - x0)) % l
            meet = 0
            if 2 * t >= d:
                meet = (2 * t - d) // l + 1
            color0 += w0 * meet
            color0 %= n

    # The chameleon (let's call him chameleon 0) initially at x0 is at (x0 + w0 * t) % l at the end,
    # Initially, its color is color0 and it changed <meet> times.
    # The final clockwise colors are a translation of the initial clockwise colors.

    x_final = [(x[i] + w[i] * t) % l for i in range(n)]
    x_final.sort()
    i = x_final.index((x0 + w0 * t) % l)
    if i + 1 < n and x_final[i] == x_final[i + 1]:
        if w0 == 1:
            i += 1
    res = [0] * n
    for k in range(n):
        color = (color0 + k) % n
        res[color] = x_final[(i+k) % n]
    return res


if __name__ == '__main__':

    n, l, t = map(int, input().split())
    x = []
    w = []
    for i in range(n):
        _x, _w = map(int, input().split())
        if _w == 2:
            _w = -1
        x.append(_x)
        w.append(_w)

    res = solve_it_chameleons(n, l, t, x, w)
    for i in range(n):
        print(res[i])
