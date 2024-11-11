import sys
from bisect import bisect_left as bisect
input = sys.stdin.readline
sys.setrecursionlimit(2 * 10**6)


def inpl():
    return list(map(int, input().split()))


class solve:
    def __init__(self, N):
        self.ans = [0] * N
        self.DP = []

    def recur(self, i, pi=-1):
        # DPテーブルを更新し、答えを求める。
        # また、巻き戻す値を覚える。
        rev_i = bisect(self.DP, self.A[i])
        if rev_i == len(self.DP):
            self.DP.append(self.A[i])
            rev_v = None
        else:
            rev_v = self.A[rev_i]
            self.DP[rev_i] = self.A[i]

        self.ans[i] = len(self.DP)

        for nv in self.edges[i]:
            if nv != pi:
                self.recur(nv, i)

        # 巻き戻す。.
        if rev_v is None:
            self.DP.pop()
        else:
            self.DP[rev_i] = rev_v

        return


def main():
    N = int(input())
    S = solve(N)
    S.A = inpl()
    S.edges = [[] for _ in range(N)]
    for _ in range(N - 1):
        u, v = inpl()
        S.edges[u - 1].append(v - 1)
        S.edges[v - 1].append(u - 1)

    S.recur(0)

    print(*S.ans, sep='\n')
    # print(edges)
    # print(parent)
    # print(DPs)


if __name__ == '__main__':
    main()
