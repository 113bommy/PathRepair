import sys
import heapq, functools, collections
import math, random
from collections import Counter, defaultdict

from atcoder.fenwicktree import FenwickTree

# available on Google, not available on Codeforces
# import numpy as np
# import scipy


def solve(grid, n):  # fix inputs here
    console("----- solving ------")
    grid = [(x-1, y-1) for x,y in grid]

    m = {}
    for i,(x,y) in enumerate(grid):
        m[x] = i
    
    grid = sorted(grid)
    console(grid)

    g = defaultdict(list)
    y_heap = []
    heapq.heapify(y_heap)

    for x,y in grid:
        if y_heap:
            ymin,xmin = y_heap[0]
            if ymin < y:
                while y_heap and y_heap[0] < (y,x):
                    ycur,xcur = heapq.heappop(y_heap)
                    g[x].append(xcur)
                    g[xcur].append(x)
                heapq.heappush(y_heap, (ymin,xmin))
        heapq.heappush(y_heap, (y,x))
        
    console(g)

    res = [0 for _ in grid]
    visited_1 = [0 for _ in grid]
    visited_2 = [0 for _ in grid]

    for i in range(n):
        if res[i]:  # if visited
            continue
        visited_1[i] = 1
        stack = [i]
        cnt = 1
        while stack:
            cur = stack.pop()
            for nex in g[cur]:
                if not visited_1[nex]:
                    cnt += 1
                    visited_1[nex] = 1
                    stack.append(nex)
                
        # print(i,cnt)
        visited_2[i] = 1
        stack = [i]
        while stack:
            cur = stack.pop()
            res[cur] = cnt
            for nex in g[cur]:
                if not visited_2[nex]:
                    visited_2[nex] = 1
                    stack.append(nex)

    console(res)
    console(visited_1)
    console(visited_2)
    res2 = [0 for _ in grid]
    for i,x in m.items():
        res2[x] = res[i]

    return res2




def console(*args):  # the judge will not read these print statement
    # print('\033[36m', *args, '\033[0m', file=sys.stderr)
    return

# fast read all
inp = sys.stdin.readlines()

for case_num in [1]:
    # read line as a string
    # strr = input()

    # read line as an integer
    nrows = int(inp[0])
    
    # read one line and parse each word as a string
    # lst = input().split()

    # read one line and parse each word as an integer
    # lst = list(map(int,input().split()))

    # read matrix and parse as integers (after reading read nrows)
    # lst = list(map(int,input().split()))
    # nrows = lst[0]  # index containing information, please change
    grid = []
    for n in range(nrows):
        grid.append(list(map(int,inp[n+1].split())))

    res = solve(grid, nrows)  # please change
    
    res = "\n".join(str(x) for x in res)
    # Google - case number required
    # print("Case #{}: {}".format(case_num+1, res))

    # Codeforces - no case number required
    print(res)
