import sys

sys.setrecursionlimit(10 ** 6)
INF = float("inf")
MOD = 10 ** 9 + 7


def input():
    return sys.stdin.readline().strip()


def main():
    N, C = map(int, input().split())
    X = []
    V = []
    for _ in range(N):
        x, v = map(int, input().split())
        X.append(x)
        V.append(v)

    # [0, i]までで得られるカロリーの最大値
    dp_right = [0] * N
    dp_right[0] = -X[0] + V[0]
    for i in range(1, N):
        dp_right[i] = dp_right[i - 1] + V[i] - (X[i] - X[i - 1])

    # [i, n - 1] までで得られるカロリーの最大値
    dp_left = [0] * N
    dp_left[N - 1] = V[N - 1] - (C - X[N - 1])
    for i in range(N - 2, -1, -1):
        dp_left[i] = dp_left[i + 1] + V[i] - (X[i + 1] - X[i])

    # 最大値に書き換える
    for i in range(1, N):
        if dp_right[i] >= dp_right[i - 1]:
            continue
        else:
            dp_right[i] = dp_right[i - 1]

    for i in range(N - 2, -1, -1):
        if dp_left[i] >= dp_left[i + 1]:
            continue
        else:
            dp_left[i] = dp_left[i + 1]

    # 折り返さない
    ans = max(0, dp_left[-1], dp_right[-1])
    # 時計周りに進んで，i個目の寿司で半時計周りに折り返す
    for i in range(N - 1):
        tmp = dp_right[i] + dp_left[i + 1] - X[i]
        if tmp > ans:
            ans = tmp

    # 最初に半時計周りに進む
    for i in range(N - 2, 0, -1):
        tmp = dp_left[i] + dp_right[i - 1] - (C - X[i])
        if tmp > ans:
            ans = tmp

    print(ans)


if __name__ == "__main__":
    main()
