from math import sin, cos, pi
def koch(px, py, qx, qy, n):
    if n == 0:
        return True
    sx = (2 * px + qx) / 3
    sy = (2 * py + qy) / 3
    tx = (px + 2 * qx) / 3
    ty = (py + 2 * qy) / 3
    ux = sx + (tx - sx) * cos(pi / 3) - (ty - sy) * sin(pi / 3)
    uy = sy + (tx - sx) * sin(pi / 3) + (ty - sy) * cos(pi / 3)
    koch(px, py, sx, sy, n - 1)
    print("{:.8f} {:.8f}".format(sx, sy))
    koch(sx, sy, ux, uy, n - 1)
    print("{:.8f} {:.8f}".format(ux, uy))
    koch(ux, uy, tx, ty, n - 1)
    print("{:.8f} {:.8f}".format(tx, ty))
    koch(tx, ty, qx, qy, n - 1)
n = int(input())
print("{:.8f} {:.8f}".format(0, 0))
koch(0, 0, 100, 0, n)
print("{:.8f} {:.8f}".format(100, 0))