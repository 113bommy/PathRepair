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
    N = II()
    a = ILI()
    return (N, a)


def solve(N, a):
    a_max = max(a)
    a_min = min(a)
    ans = ""
    if a_max - a_min > 1:
        ans = "No"
    elif a_max - a_min == 1:
        n_alone = a.count(a_min)
        n_group = a.count(a_max)
        if n_alone < a_max and 2 ** (a_max - n_alone) <= n_group:
            ans = "Yes"
        else:
            ans = "No"
    elif a_max - a_min == 0:
        if a[0] == N - 1 or a[0] * 2 <= N:
            ans = "Yes"
        else:
            ans = "No"

    return ans


def main():
    params = read()
    print(solve(*params))


if __name__ == "__main__":
    main()
