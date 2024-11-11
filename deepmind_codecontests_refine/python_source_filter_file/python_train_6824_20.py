import sys

n = int(sys.stdin.readline().strip())
c = list(map(int, sys.stdin.readline().strip().split()))
w = [sys.stdin.readline().strip() for _ in range(n)]


def solve(n, c, w):
    _MAX_VAL = 10 ** 5 * 10 ** 9
    t1 = [0] + [_MAX_VAL] * (n - 1)
    t2 = [c[0]] + [_MAX_VAL] * (n - 1)

    w1 = w
    w2 = [_[::-1] for _ in w]

    for i in range(1, n):
        if w1[i] > w1[i - 1]:
            t1[i] = min(t1[i], t1[i - 1])
        if w1[i] > w2[i - 1]:
            t1[i] = min(t1[i], t2[i - 1])

        if w2[i] > w1[i - 1]:
            t2[i] = min(t2[i], t1[i - 1] + c[i])
        if w2[i] > w2[i - 1]:
            t2[i] = min(t2[i], t2[i - 1] + c[i])

        if t1[i] == _MAX_VAL and t2[i] == _MAX_VAL:
            return -1

    return min(t1[n - 1], t2[n - 1])


print(solve(n, c, w))
