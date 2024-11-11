from fractions import Fraction


def main():
    a, b, c, d = map(int, input().split())

    if Fraction(a, b) == Fraction(c, d):
        print('0/1')
        return

    w = (b - d * Fraction(a, c)) / b
    h = (a - c * Fraction(b, d)) / a

    if w < 0:
        w = float('infinity')

    if h < 0:
        h = float('infinity')

    ans = min(w, h)
    print(ans)


if __name__ == "__main__":
    main()
