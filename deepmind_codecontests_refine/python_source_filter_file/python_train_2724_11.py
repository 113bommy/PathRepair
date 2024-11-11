from sys import stdin

MOD = 100000000


def solve(n1, n2, k1, k2):
    table = [[[[-1] * (k2 + 1) for k in range(k1 + 1)] for j in range(n2 + 1)]
             for i in range(n1 + 1)]

    for f in range(n1 + 1):
        for h in range(n2 + 1):
            for kf in range(k1 + 1):
                for kh in range(k2 + 1):
                    ans = 0
                    if f + h == 0:
                        ans = 1
                    else:
                        if f > 0 and kf > 0:
                            ans = (ans + table[f - 1][h][kf - 1][k2]) % MOD
                        if h > 0 and kh > 0:
                            ans = (ans + table[f][h - 1][k1][kh - 1]) % MOD

                    table[f][h][kf][kh] = ans

    return table[n1][n2][k1][k2]


if __name__ == "__main__":
    N1, N2, K1, K2 = tuple(map(int, stdin.readline().split(" ")))
    print(solve(N2, N2, K1, K2))
