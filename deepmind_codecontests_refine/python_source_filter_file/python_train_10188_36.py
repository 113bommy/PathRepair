import sys

sys.setrecursionlimit(10 ** 7)
input = sys.stdin.readline
f_inf = float('inf')
mod = 10 ** 9 + 7


def resolve():
    n = int(input())
    P = list(map(int, input().split()))
    MAX = 10 ** 8
    A = list(range(1, MAX + 2, MAX // (n - 1)))
    T = list(range(1, n + 1))
    B = [0] * n
    for i in range(n):
        idx = P[i] - 1
        B[idx] = T[i] - A[idx]
    mi = min(B)
    if mi <= 0:
        d = mi * -1 + 1
        B = [b + d for b in B]
    print(*A)
    print(*B)


if __name__ == '__main__':
    resolve()
