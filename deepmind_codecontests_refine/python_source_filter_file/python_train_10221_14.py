import math

def lcd(a, b):
    return int(int(a) * int(b) / math.gcd(int(a), int(b)))

n, m, q = [int(i) for i in input().split()]

a = lcd(n, m)
inp = int(a / n)
out = int(a / m)
stp = lcd(inp, out)

for i in range(0, q):
    sx, sy, ex, ey = [int(i) for i in input().split()]

    if sx == 1:
        sy = int(sy * inp)
    else:
        sy = int(sy * out)

    if ex == 1:
        ey = int(ey * inp)
    else:
        ey = int(ey * out)

    if (int(int((sy + stp - 1)) // stp)) == int((int((ey + stp - 1)) // stp)):
        print("YES\n")
    else:
        print("NO\n")