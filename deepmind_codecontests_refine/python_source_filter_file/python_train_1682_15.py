from math import gcd


def main():
    n, m = map(int, input().split())
    xs = list(map(int, input().split()))
    ps = list(map(int, input().split()))

    t = xs[1] - xs[0]
    for i in range(2, n):
        t = gcd(t, xs[i] - xs[i - 1])

    i = 0
    while i < m and t % ps[i] != 0:
        i += 1

    if i == m:
        print('NO')
        return

    print('YES')
    print(xs[0], ps[i])


if __name__ == '__main__':
    main()
