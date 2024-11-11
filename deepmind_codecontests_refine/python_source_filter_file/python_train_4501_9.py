from math import gcd
import sys


def input():
    return sys.stdin.readline().rstrip()


MOD = 998244353


class CHOOSE():
    def __init__(self, N, mod=998244353):
        self.power = [1 for _ in range(N+1)]
        self.rev = [1 for _ in range(N+1)]
        self.mod = mod
        for i in range(2, N+1):
            self.power[i] = (self.power[i-1]*i) % self.mod
        self.rev[N] = pow(self.power[N], self.mod-2, self.mod)
        for j in range(N, 0, -1):
            self.rev[j-1] = (self.rev[j]*j) % self.mod

    def c(self, K, R):
        if not (0 <= R <= K):
            return 0
        else:
            return ((self.power[K])*(self.rev[K-R])*(self.rev[R])) % self.mod

    def p(self, K, R):
        if not (0 <= R <= K):
            return 0
        else:
            return (self.power[K])*(self.rev[K-R]) % self.mod


c = CHOOSE(200010)


def slv():

    n, m = map(int, input().split())
    if n == 2:
        print(0)
    else:
        ans = c.c(n, m - 1)*(n - 2)*pow(2, n - 3, MOD)
        print(ans % MOD)
    return


def main():
    #t = int(input())
    t = 1
    for _ in range(t):
        slv()
    return


if __name__ == "__main__":
    # in_txt = open("in.txt", "r")
    # out_txt = open("out.txt", "w")
    # sys.stdin = in_txt
    # sys.stdout = out_txt
    main()
