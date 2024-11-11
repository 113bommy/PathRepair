import sys
sys.setrecursionlimit(10**7)
INF = 10 ** 18
MOD = 10 ** 9 + 7
def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x) - 1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def II(): return int(sys.stdin.readline())
def SI(): return input()
from math import factorial
from collections import Counter

def main():
    N, X = LI()
    S = LI()
    S.sort(reverse=True)
    dp = Counter()
    dp[X] = factorial(N)
    for i, s in enumerate(S):
        pre = dp
        dp = Counter()
        for n, cnt in pre.items():
            if s <= n:
                dp[n] += cnt * (N - 1 - i) // (N - i)
                dp[n % s] += cnt // (N - i)
            else:
                dp[n] = cnt
    ans = 0
    for n, cnt in dp.items():
        ans = (ans + (n * cnt) % MOD) % MOD

    return ans

print(main())