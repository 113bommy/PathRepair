# coding: utf-8
import array, bisect, collections, copy, heapq, itertools, math, random, re, string, sys, time
sys.setrecursionlimit(10 ** 7)
INF = 10 ** 20
MOD = 10 ** 9 + 7


def II(): return int(input())
def ILI(): return list(map(int, input().split()))
def IAI(LINE): return [ILI() for __ in range(LINE)]
def IDI(): return {key: value for key, value in ILI()}


def read():
    N, M = ILI()
    return N, M


def solve(N, M):
    if abs(N - M) >= 2:
        return 0
    elif abs(N - M) == 1:
        num_min = min(N, M)
        ans = ((math.factorial(num_min) ** 2) * (num_min + 1)) % MOD
        return ans
    elif abs(N - M) == 0:
        ans = (2 * (math.factorial(N) ** 2)) % MOD
        return ans


def main():
    params = read()
    print(solve(*params))


if __name__ == "__main__":
    main()
