# encoding: utf-8
import sys
# input = sys.stdin.readline
inf = 10 ** 18
 
N = int(input())
ab = [list(map(int, input().split())) for _ in range(N - 1)]
 
cnct = [[] for _ in range(N)]
for ai, bi in ab:
    cnct[ai - 1].append(bi - 1)
    cnct[bi - 1].append(ai - 1)
# print("#", cnct)
 
# start from a leaf
for src in range(N):
    if len(cnct[src]) > 1: break
# print("#", src)
 
import heapq
 
len_max = 0
for i in range(2):
    q = []
    d = [inf] * N
    prev = [None] * N
    #
    heapq.heappush(q, (0, src))
    d[src] = 0
    while len(q) > 0:
        du, u = heapq.heappop(q)
        # print("#", du, u)
        for dst in cnct[u]:
            # print("##", dst)
            if d[dst] > du + 1:
                d[dst] = du + 1
                prev[dst] = u
                heapq.heappush(q, (du + 1, dst))
    #
    if len_max == max(d):
        break
    elif len_max < max(d):
        len_max = max(d)
        src = d.index(len_max)
    else:
        continue
 
# print("#", len_max)
 
if len_max % 3 == 1:
    print('Second')    
else:
    print('First')