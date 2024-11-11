import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    n = int(readline())
    p = list(map(int, readline().split()))
    a = [0] * n
    b = [0] * n

    for i, x in enumerate(p):
        y = p[i] - 1
        a[y] = (y + 1) * (5 * 10 ** 4) + 2*i
        b[y] = (n - y) * (5 * 10 ** 4)

    print(*a)
    print(*b)


if __name__ == '__main__':
    main()
