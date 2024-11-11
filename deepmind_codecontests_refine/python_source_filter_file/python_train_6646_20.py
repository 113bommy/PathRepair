import bisect
import copy
import heapq
import sys
import itertools
import math
import queue
input = sys.stdin.readline
sys.setrecursionlimit(1000000)
# mod = 10 ** 9 + 7
mod = 998244353 

def read_values(): return map(int, input().split())
def read_index(): return map(lambda x: int(x) - 1, input().split())
def read_list(): return list(read_values())
def read_lists(N): return [read_list() for n in range(N)]
def init_dp1(init, N): return [init for _ in range(N)]
def init_dp2(init, N, M): return [[init for _ in range(M)] for _ in range(N)]


class V:
    def __init__(self, f, v=None):
        self.f = f
        self.v = v
 
    def __str__(self):
        return str(self.v)
 
    def ud(self, n):
        if n is None:
            return

        if self.v is None:
            self.v = n
            return
        self.v = self.f(self.v, n) 


def f(A, S):
    T = [0] * len(A[0])
    for a in A:
        for k in a:
            if k in S:
                continue
            T[k] += 1
            break
    
    v = max(T)
    return (T.index(v), v)


def main():
    N, M = read_values()
    A = [list(read_index()) for _ in range(N)]

    K = [0] * N

    res = V(min, M)
    S = set()
    for _ in range(M - 1):
        k, v = f(A, S)
        S.add(k)
        res.ud(v)

    print(res)


if __name__ == "__main__":
    main()

