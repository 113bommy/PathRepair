# 解説と 提出 #15122924 を参考に作成.
# 遅い. PyPyで出すと通る. はず.

# import sys
# sys.setrecursionlimit(10 ** 6)
# import bisect
# from collections import deque
# from decorator import stop_watch
#
#
# @stop_watch
def solve(N, X, Y, P):
    inf = 10 ** 18
    cnb_N = 2 ** N
    # 前計算
    # # 集落の部分集合毎の、Y軸X軸へのそれぞれの最短経路
    to_x = [[0] * N for _ in range(cnb_N)]
    to_y = [[0] * N for _ in range(cnb_N)]
    for cn in range(cnb_N):
        for n in range(N):
            to_x[cn][n] = abs(X[n]) * P[n]
            to_y[cn][n] = abs(Y[n]) * P[n]
            for n2 in range(N):
                if cn >> n2 & 1:
                    to_x[cn][n] = min(to_x[cn][n], abs(X[n] - X[n2]) * P[n])
                    to_y[cn][n] = min(to_y[cn][n], abs(Y[n] - Y[n2]) * P[n])

    # 実計算
    # # 各集落の集合に対して、Y軸を取った場合とX軸を取った場合で最短となる経路を算出
    ans = [inf] * (N + 1)
    for cn in range(cnb_N):
        count = 0
        for i in range(N):
            count += 1 if cn >> i & 1 else 0
        cn2 = cn
        while cn2 >= 0:
            cn2 = cn2 & cn
            subsum = 0
            for n in range(N):
                if not (cn >> n & 1):
                    subsum += min(to_x[cn - cn2][n], to_y[cn2][n])
            ans[count] = min(ans[count], subsum)
            cn2 -= 1

    for n in range(N + 1):
        print(ans[n])


if __name__ == '__main__':
    # S = input()
    N = int(input())
    # N, M = map(int, input().split())
    X, Y, P = [], [], []
    for _ in range(N):
        tmp = [int(i) for i in input().split()]
        X.append(tmp[0])
        Y.append(tmp[1])
        P.append(tmp[2])
    solve(N, X, Y, P)
