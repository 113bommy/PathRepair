import sys

sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")

def main():
    def cost(l, r):
        if l + 2 == r:
            return aa[l] + aa[l + 1]
        if l + 1 == r:
            return 0
        if dp[l][r] != -1:
            return dp[l][r]
        res = 10 ** 10
        for m in range(l + 1, r):
            res = min(res, cost(l, m) + cost(m, r))
        res += cumsum_aa[r] - cumsum_aa[l]
        dp[l][r] = res
        return res

    n = int(input())
    aa = list(map(int, input().split()))
    dp = [[-1] * (n + 1) for _ in range(n + 1)]
    cumsum_aa = [0]
    for i, a in enumerate(aa):
        cumsum_aa.append(cumsum_aa[i] + a)
    print(cost(0, n))

main()
