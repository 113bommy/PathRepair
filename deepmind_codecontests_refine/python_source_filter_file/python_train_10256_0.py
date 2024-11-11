from fractions import Fraction


def higher(x1, y1, x2, y2):
    if x1 == 0:
        if x2 == 0:
            return 


def min_days(p, q, pr):
    ma = max(a for a, b in pr)
    mb = max(b for a, b in pr)
    pr.sort(key=lambda t: (t[0], -t[1]))
    ch = [(0, mb)]
    for a, b in pr:
        if a == ch[-1][0]:
            continue
        while (
            len(ch) >= 2
            and ((b-ch[-2][1])*(ch[-1][1]-ch[-2][1])
                 >= (a-ch[-2][0])*(ch[-1][0]-ch[-2][0]))
        ):
            ch.pop()
        ch.append((a, b))
    ch.append((ma, 0))

    a1, b1 = None, None
    for a2, b2 in ch:
        if a1 is not None:
            d = (a2-a1)*q + (b1-b2)*p
            s = Fraction(b1*p-a1*q, d)
            if 0 <= s <= 1:
                return Fraction(d, a2*b1 - a1*b2)
        a1, b1 = a2, b2


if __name__ == '__main__':
    n, p, q = map(int, input().split())
    pr = []
    for _ in range(n):
        a, b = map(int, input().split())
        pr.append((a, b))
    print("{:.7f}".format(float(min_days(p, q, pr))))
