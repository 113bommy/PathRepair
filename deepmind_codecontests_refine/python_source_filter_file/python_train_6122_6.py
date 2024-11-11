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

def main():
    N = II()
    S = LI()
    ans = 0
    for C in range(1, N):
        tmp = 0
        L = 0
        R = N - 1
        lim = (N - 1 - C) if (N - 1) % C else (N - 1) // 2
        while L < lim:
            tmp += S[L] + S[R]
            ans = max(ans, tmp)
            L += C
            R -= C
    return ans

print(main())