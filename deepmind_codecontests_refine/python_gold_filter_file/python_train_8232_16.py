n, h, a, b, k = input().split()
n, h, a, b, k = int(n), int(h), int(a), int(b), int(k)

for i in range(k):
    ta, fa, tb, fb = input().split()
    ta, fa, tb, fb = int(ta), int(fa), int(tb), int(fb)
    x, y = int(), int()
    if (ta == tb):
        print(abs(fa - fb))
    else:
        if (fa >= a and fa <= b):
            x = 0
            y = fa
        elif abs(fa - a) <= abs(fa - b):
            x = abs(fa - a)
            y = a
        else:
            x = abs(fa - b)
            y = b
        print(x + abs(ta - tb) + abs(fb - y))
