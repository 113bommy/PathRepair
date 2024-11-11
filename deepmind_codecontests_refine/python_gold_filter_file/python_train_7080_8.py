import math


def koch(m, p1, p2):
    if m == 0:
        return

    s = [(2 * p1[0] + p2[0]) / 3, (2 * p1[1] + p2[1]) / 3]
    t = [(p1[0] + 2 * p2[0]) / 3, (p1[1] + 2 * p2[1]) / 3]
    u = [(t[0] - s[0]) * math.cos(math.pi / 3) - (t[1] - s[1]) * math.sin(math.pi / 3) + s[0],
         (t[0] - s[0]) * math.sin(math.pi / 3) + (t[1] - s[1]) * math.cos(math.pi / 3) + s[1]]

    koch(m-1, p1, s)
    print(s[0], s[1])
    koch(m-1, s, u)
    print(u[0], u[1])
    koch(m-1, u, t)
    print(t[0], t[1])
    koch(m-1, t, p2)


n = int(input())
print(0, 0)
koch(n, [0, 0], [100, 0])
print(100, 0)