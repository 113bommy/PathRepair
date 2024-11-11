import sys
from math import floor, ceil

IS_LOCAL = False


def read_one(dtype=int):
    return dtype(input())


def read_multiple(f, dtype=int):
    return f(map(dtype, input().split()))


def main():
    a = '01100010'
    b = '00110'

    if not IS_LOCAL:
        a = input()
        b = input()

    def cst(x):
        return 0 if x == '0' else 1

    def rsum(arr):
        return sum(map(cst, arr))

    sb, lb = rsum(b), len(b)
    s = None
    res = 0
    for i in range(lb - 1, len(a)):
        if s is None:
            s = rsum(a[:i])
        else:
            s = s - cst(a[i - lb]) + cst(a[i])

        if (s - sb) % 2 == 0:
            res += 1

    print(res)


if __name__ == "__main__":
    if len(sys.argv) > 1 and sys.argv[1] == 'True':
        IS_LOCAL = True
    main()
