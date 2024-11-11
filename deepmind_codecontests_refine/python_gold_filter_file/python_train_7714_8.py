import itertools
import math


def main():
    l, r = [int(v) for v in input().split()]
    print('YES')
    q = l
    while q < r:
        print(q, q+1)
        q += 2


if __name__ == '__main__':
    main()
