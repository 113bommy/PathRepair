import sys
from heapq import heappush, heappop

readline = sys.stdin.readline


def solve():
    N = int(readline())

    left = [[] for _ in range(N)]
    right = [[] for _ in range(N)]
    ans = 0
    for _ in range(N):
        K, L, R = map(int, readline().split())
        if L > R:
            ans += R
            left[K - 1].append(R - L)
        else:
            ans += L
            if 0 <= N - K - 1:
                right[N - K - 1].append(L - R)

    for vec in (left, right):
        hq = []
        n = len(vec)
        for idx in range(N):
            for p in vec[idx]:
                heappush(hq, p)
            while len(hq) > min(idx + 1, n):
                heappop(hq)

        ans -= sum(hq)

    return ans


def main():
    T = int(readline())

    ans = [0] * T
    for i in range(T):
        ans[i] = solve()

    print('\n'.join(map(str, ans)))
    return


if __name__ == '__main__':
    main()
