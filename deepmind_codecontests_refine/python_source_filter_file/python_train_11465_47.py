import sys

tc = int(sys.stdin.readline())
for _ in range(tc):
    d = int(sys.stdin.readline())
    if d ** 2 - 4 * d < 0:
        print('N')
    else:
        b1 = (d + (d ** 2 - 4 * d) ** 0.5) / 2
        a1 = d - b1
        b2 = (d - (d ** 2 - 4 * d) ** 0.5) / 2
        a2 = d - b2
        if a1 >= 0 and b1 >= 0:
            print('Y %f %f' % (a1, b1))
        elif a2 >= 0 and b2 >= 0:
            print('Y %f %f' % (a2, b2))
        else:
            print('N')