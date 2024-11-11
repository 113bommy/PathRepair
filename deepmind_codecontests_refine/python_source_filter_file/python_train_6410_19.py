from fractions import gcd
# from datetime import date, timedelta
from heapq import*
import math
from collections import defaultdict, Counter, deque
from bisect import *
import itertools
import fractions
import sys
sys.setrecursionlimit(10 ** 7)
MOD = 10 ** 9 + 7
# input = sys.stdin.readline



def main():
    n, m, k, x, y = map(int, input().split())
    grid = [[0 for i in range(m)] for j in range(n)]
    
    if n == 1:
        V = k // m
        grid = [V] * m
        for i in range(k - m*(k//m)):
            grid[i] += 1
        print(max(grid),min(grid),grid[y])
        exit()
    
    A = (k - n * m) // (2*m * (n - 1)) + 1 
    B = 1 + (A - 1) * 2
    C = k - (n * m + (A - 1) * (n - 1) * m*2)
    
    for i in range(n):
        for j in range(m):
            if i == 0 or i == n - 1:
                grid[i][j] = A
            else:
                grid[i][j] = B

    #if C >= m * (n - 1):
    while C > 0:
        for i in range(n-2,-1,-1):
            for j in range(m):
                if C == 0:
                    break
                grid[i][j] +=1
                C -= 1
            if C == 0:
                break
        for i in range(1, n):
            for j in range(m):
                if C == 0:
                    break
                grid[i][j] += 1
                C -= 1
            if C == 0:
                break
            
    # else:
    #     while C > 0:
    #         for i in range(n-2,-1,-1):
    #             for j in range(m):
    #                 if C == 0:
    #                     break
    #                 grid[i][j] +=1
    #                 C -= 1
    #         for i in range(n-2, -1, -1):
    #             for j in range(m):
    #                 if C == 0:
    #                     break
    #                 grid[i][j] += 1
    #                 C -= 1
    
    ma, mi, ser = -1, float("inf"), 0
    for i in range(n):
        for j in range(m):
            if ma < grid[i][j]:
                ma = grid[i][j]
            if mi > grid[i][j]:
                mi = grid[i][j]
            
            if i == x - 1 and j == y - 1:
                ser = grid[i][j]
    print(ma, mi, ser)


if __name__ == '__main__':
    main()
