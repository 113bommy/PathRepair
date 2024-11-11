import math
angle = math.pi / 3 # 60度

def koch(p1, p2, n):
    if n == 0:
        return
    s = ((p1[0] * 2 + p2[0]) / 3, (p1[1] * 2 + p2[1]) / 3)
    t = ((p1[0] + p2[0] * 2) / 3, (p1[1] + p2[1] * 2) / 3)
    u = ((t[0] - s[0]) * math.cos(angle) - (t[1] - s[1]) * math.sin(angle) + s[0], \
        (t[0] - s[0]) * math.sin(angle) - (t[1] - s[1]) * math.cos(angle) + s[1])

    koch(p1, s, n-1)
    print("{0:.8f} {1:.8f}".format(s[0], s[1]))
    koch(s, u, n-1)
    print("{0:.8f} {1:.8f}".format(u[0], u[1]))
    koch(u, t, n-1)
    print("{0:.8f} {1:.8f}".format(t[0], t[1]))
    koch(t, p2, n-1)

n = int(input())
print("{0:.8f} {1:.8f}".format(0.0, 0.0))
koch((0.0, 0.0), (100.0, 0.0), n)
print("{0:.8f} {1:.8f}".format(100.0, 0.0))
