from bisect import bisect_left, bisect_right
import math
import sys
input = sys.stdin.readline


def main():
    N = int(input())
    X = list(map(int, input().split()))
    L = int(input())
    ln = int(math.log(N, 2))
    dpl = [[0] * N for _ in range(ln+1)]
    dpr = [[0] * N for _ in range(ln+1)]
    l = 0
    r = 0
    for i in range(N):
        x = X[i]
        while X[l] + L < x:
            l += 1
        while r < N-1 and x + L >= X[r+1]:
            r += 1
        dpl[0][i] = l
        dpr[0][i] = r
    for k in range(1, ln+1):
        for i in range(N):
            dpl[k][i] = dpl[k-1][dpl[k-1][i]]
            dpr[k][i] = dpr[k-1][dpr[k-1][i]]
    Q = int(input())
    for _ in range(Q):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        ans = 0
        if a < b:
            for k in range(ln+1)[::-1]:
                if dpr[k][a] <= b:
                    a = dpr[k][a]
                    ans += 2**k
            if a < b:
                ans += 1
        else:
            # a > b
            for k in range(ln+1)[::-1]:
                if dpl[k][a] >= b:
                    a = dpl[k][a]
                    ans += 2**k
            if a > b:
                ans += 1
        print(ans)


if __name__ == "__main__":
    main()
