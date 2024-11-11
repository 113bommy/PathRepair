import math


def D(d):
    res = d**2 - 4 *d
    if res < 0:
        return -1
    return math.sqrt(res)


def solve():
    d = float(input())
    res = D(d)
    if res == -1:
        print('N')
        return
    a = (d + res) / 2
    b = d - a
    print('Y %.7f %.7f' % (a, b))


def main():
    t = int(input())
    for i in range(t):
        solve()


if __name__ == '__main__':
    main()