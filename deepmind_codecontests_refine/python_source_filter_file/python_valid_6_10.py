import sys 
from sys import stdin

from bisect import bisect_left, bisect_right
from collections import defaultdict, deque, namedtuple
from math import gcd, ceil, floor
from itertools import combinations, permutations


def main_1():
    # 用数组维护出度，TLE
    test = 1

    for idt in range(test):
        # n, m = map(int, input().split())
        n, m = map(int, stdin.readline().split())
        ins = [0] * n 
        for i in range(m):
            u, v = map(int, input().split())
            ins[min(u, v) - 1] += 1 
        query = int(input())
        # print("in_s", ins)
        scores = ins.copy()

        for idq in range(query):
            op = list(map(int, input().split()))
            if len(op) == 3:
                ty, u, v = op 
                if ty == 1:
                    scores[min(u, v) - 1] += 1 
                else:
                    scores[min(u, v) - 1] -= 1 
            else:
                res = n
                for i in scores:
                    if i >= 1:
                        res -= 1 
                print(res)
                scores = ins.copy()

    return 

def main():
    # 用数字维护出度
    test = 1

    for idt in range(test):
        # n, m = map(int, input().split())
        n, m = map(int, stdin.readline().split())
        ins = [0] * (n + 1)
        ans = 0
        for i in range(m):
            u, v = map(int, input().split())
            u = min(u, v)
            ins[u] += 1 
            if ins[u] == 1:
                ans += 1

        q = int(input())
        back_up = ans 
        for idq in range(q):
            op = list(map(int, stdin.readline().split()))
            if len(op) == 3:
                t, u, v = op 
                u = min(u, v)
                if t == 1:
                    ins[u] += 1 
                    if ins[u] == 1:
                        ans += 1
                else:
                    ins[u] -= 1 
                    if ins[u] == 0:
                        ans -= 1 
            else:
                print(n - ans)
                ans = back_up  # 备份
    return 


if __name__ == '__main__':
    main()