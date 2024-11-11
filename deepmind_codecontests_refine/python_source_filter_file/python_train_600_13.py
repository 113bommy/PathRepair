import bisect
import copy
import heapq
import sys
import itertools
import math
import queue
from functools import lru_cache
input = sys.stdin.readline
sys.setrecursionlimit(1000000)
mod = 10 ** 9 + 7 

def read_values(): return map(int, input().split())
def read_index(): return map(lambda x: int(x) - 1, input().split())
def read_list(): return list(read_values())
def read_lists(N): return [read_list() for n in range(N)]


def main():
    N, M = read_values()
    T = read_lists(M)
    T.sort()

    S = []
    C = [10 ** 10] * N
    C[0] = 0
    t = 0
    for i in range(N - 1):
        if i != 0 and len(S) == 0:
            print(-1)
            return

        c, r = (0, 0) if len(S) == 0 else S[0]
        while t < M:
            ll, rr, cc = T[t]
            ll -= 1
            rr -= 1
            if ll > i:
                break
                
            C[rr] = min(C[rr], c + cc)
            heapq.heappush(S, (C[rr], rr))
            t += 1

        while S:
            if S[0][1] > i:
                break
            heapq.heappop(S)

    print(C[-1])


if __name__ == "__main__":
    main()

