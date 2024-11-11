import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    n, a, b, k = list(map(int, readline().split()))
    M = 998244353

    h = (n + 1) // 2
    l = h + 1
    com = [0] * l
    com[0] = 1

    for i in range(1, l):
        t = com[i - 1] * (n + 1 - i)
        t *= pow(i, M - 2, M)
        t %= M
        com[i] = t

    ans = 0
    rng = min(k // a + 1, n)

    for x in range(rng):
        res = k - a * x
        if res % b == 0:
            y = res // b
            if y > n:
                continue
            if x > h:
                x = n - x
            if y > h:
                y = n - y
            add = com[x] * com[y]
            ans += add
            ans %= M

    print(ans)

if __name__ == '__main__':
    main()
