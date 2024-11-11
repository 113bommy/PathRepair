import sys
from functools import lru_cache

sys.setrecursionlimit(10**6)


def main():
    T = int(input())
    TESTCASEs = [list(map(int, input().split())) for _ in range(T)]


    def calc_cost(N, A, B, C, D):


        @lru_cache(maxsize=None)
        def calc(N):
            if N == 0:
                return 0
            if N == 1:
                return D

            cost = N * D
            
            for T, Tcost in ((2, A), (3, B), (5, C)):
                div, mod = divmod(N, T)

                cost = min(cost, calc(div) + Tcost + mod * D)
                if mod:
                    cost = min(cost, calc(div + 1) + Tcost + (T - mod) * D)

            return cost


        return calc(N)


    for TESTCASE in TESTCASEs:
        total_cost = calc_cost(*TESTCASE)
        print(total_cost)


if __name__ == '__main__':
    main()

sys.exit()
