import sys
from bisect import bisect

def solve():
    input = sys.stdin.readline
    N, M, V, P = map(int, input().split())
    A = [int(a) for a in input().split()]
    A.sort()
    border = A[N - P]

    low, high = -1, N
    while high - low > 1:
        mid = (low + high) //2
        point = A[mid] + M
        if point < border: low = mid
        elif mid >= N - P: high = mid
        else:
            space = (mid + P) * M
            for i in range(mid + 1, N - P + 1 ): space += point - A[i]
            if space >= M * V: high = mid
            else: low = mid
    print(N - low - 1)
    return 0

if __name__ == "__main__":
    solve()
