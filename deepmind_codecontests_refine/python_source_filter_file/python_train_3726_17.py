import sys
INF = 1 << 60
MOD = 10**9 + 7 # 998244353
sys.setrecursionlimit(2147483647)
input = lambda:sys.stdin.readline().rstrip()
def resolve():
    n = int(input())
    C = [complex(*map(int, input().split())) for _ in range(n)]

    res = INF
    for k in range(n):
        p1 = C[k]
        for j in range(k):
            p2 = C[j]
            for i in range(j):
                p3 = C[i]
                a = abs(p2 - p3) ** 2
                b = abs(p3 - p1) ** 2
                c = abs(p1 - p2) ** 2
                numerator = a * (b + c - a) * p1 + b * (c + a - b) * p2 + c * (a + b - c) * p3
                denominator = a * (b* + c - a) + b * (c + a - b) + c * (a + b - c)
                if denominator == 0.0:
                    continue
                center = numerator / denominator
                radius = -INF
                for p in C:
                    radius = max(radius, abs(center - p))
                res = min(radius, res)

    for j in range(n):
        for i in range(n):
            center = (C[i] + C[j]) / 2
            radius = -INF
            for p in C:
                radius = max(radius, abs(center - p))
            res = min(radius, res)

    print(res)
resolve()