#!/usr/bin/env python3


def main():
    s = input().split()
    n = int(s[-1])
    xs = [1] + [int(x + '1') for x in s[1:-2:2]]

    d = sum(xs) - n
    if d > 0:
        for i, x in enumerate(xs):
            if d == 0:
                break
            if x < 0:
                xs[i] = -min(n, d + 1)
                d -= xs[i] + 1
    elif d < 0:
        for i, x in enumerate(xs):
            if d == 0:
                break
            if x > 0:
                xs[i] = min(n, -d + 1)
                d += xs[i] - 1

    if sum(xs) == n:
        print('Possible')
        print('{} = {}'.format(' '.join(('+ ' if x > 0 else '- ') + str(abs(x)) for x in xs)[2:], n))
    else:
        print('Impossible')


if __name__ == "__main__":
    main()
