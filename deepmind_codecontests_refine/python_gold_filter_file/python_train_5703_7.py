# coding: utf-8
import sys
#from operator import itemgetter
sysread = sys.stdin.buffer.readline
read = sys.stdin.buffer.read
#from heapq import heappop, heappush
#from collections import defaultdict
sys.setrecursionlimit(10**7)
#import math
#from itertools import product, accumulate, combinations, product
import bisect
#import numpy as np
#from copy import deepcopy
#from collections import deque

INF = 1 << 50

def generate_dist_arr(X, Y, P):
    N = len(X)
    dist_arr_x = [[] for _ in range(1<<N)]
    dist_arr_y = [[] for _ in range(1<<N)]
    for j in range(1 << N):  # x-y-lines
        x_lines_list = [0]
        y_lines_list = [0]
        for k in range(N):
            if j >> k & 1:
                x_lines_list.append(X[k])
                y_lines_list.append(Y[k])

        dist_xx, dist_yy = [INF] * N, [INF] * N
        x_lines_list = sorted(x_lines_list)
        y_lines_list = sorted(y_lines_list)
        for idx, x in enumerate(X):
            v = bisect.bisect_left(x_lines_list, x)
            pre_x = x_lines_list[min(v-1,  0)]
            post_x = x_lines_list[min(v, len(x_lines_list)-1)]
            dist_xx[idx] = min(abs(pre_x - x), abs(post_x - x)) * P[idx]
        dist_arr_x[j] = dist_xx

        for idx, y in enumerate(Y):
            v = bisect.bisect_left(y_lines_list, y)
            pre_y = y_lines_list[max(v-1, 0)]
            post_y = y_lines_list[min(v, len(y_lines_list) - 1)]
            dist_yy[idx] = min(abs(pre_y - y), abs(post_y - y)) * P[idx]
        dist_arr_y[j] = dist_yy
    return dist_arr_x, dist_arr_y

def calc(val_list):
    val_list = sorted(val_list)
    n = len(val_list)
    dp = [[INF] * (n+1) for _ in range(n+1)]
    dp[0][0] = 0

    for l in range(n+1):
        for r in range(l+1, n+1):
            next_dist = INF
            for k in range(l+1, r+1):
                sum = 0
                for v in range(l+1, r+1):
                    sum += abs(val_list[v-1][0] - val_list[k-1][0]) * val_list[v-1][1]
                next_dist = min(next_dist, sum)
            for j in range(n):
                dp[r][j + 1] = min(dp[r][j + 1], dp[l][j] + next_dist)
            # 0-line
            sum = 0
            for v in range(l + 1, r + 1):
                sum += abs(val_list[v-1][0]) * val_list[v-1][1]
            next_dist = sum

            for j in range(n+1):
                dp[r][j] = min(dp[r][j], dp[l][j]+next_dist)
    return dp


def run():
    N = int(sysread())
    X, Y = [], []

    for i in range(1, N+1):
        x,y,p = map(int, sysread().split())
        X.append((x, p))
        Y.append((y, p))

    ans = [INF] * (N + 1)


    for i in range(1 << N):# x-y-directions
        x_town_list = []
        y_town_list = []
        for k in range(N):
            if i >> k & 1:
                x_town_list.append(X[k])
            else:
                y_town_list.append(Y[k])
        #print('x', x_town_list)
        #print('y', y_town_list)
        dp_x = calc(x_town_list)[-1]
        dp_y = calc(y_town_list)[-1]
        #print(calc(x_town_list))
        #print(calc(y_town_list), '\n')
        #print(bin(i))
        #print(dist_towns_x)
        #print(dist_towns_y)

        for i in range(len(dp_x)):
            for j in range(len(dp_y)):
                val = dp_x[i] + dp_y[j]
                ans[i + j] = min(ans[i + j], val)


    for a in ans:
        print(a)


if __name__ == "__main__":
    run()