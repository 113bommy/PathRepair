from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,copy,time
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))
def inpl_str(): return list(sys.stdin.readline().split())


N,Q = inpl()
MAP = [[False,False] for _ in range(N)]
block = set()

ans = ""
for _ in range(Q):
    x,y = inpl()
    x -= 1; y-= 1

    if MAP[y][x] == False: # 追加
        MAP[y][x] = True
        nx = x^1
        for ny in range(max(0,y-1),min(y+2,N)):
            if MAP[ny][nx]:
                if x == 0:
                    block.add((y,ny))
                else:
                    block.add((ny,y))
    else: # 削除
        MAP[y][x] = False
        nx = x^1
        for ny in range(max(0,y-1),min(y+2,N)):
            if x == 0:
                block.discard((y,ny))
            if x == 0:
                block.discard((ny,y))


    # print(block)
    if len(block) > 0:
        ans += "No\n"
    else:
        ans += "Yes\n"

print(ans)
