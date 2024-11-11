''' Hey stalker :) '''
INF = 10 ** 10
def main():
    #print = out.append
    ''' Cook your dish here! '''
    n = get_int()
    mat = [[] for _ in range(n)]
    res = [['A' for _ in range(n)]for _ in range(n)]
    for j in range(n):
        li = get_list()
        for i in range(0, 2*n, 2):
            x,y = li[i]-1, li[i+1]-1
            mat[j].append([x,y])
    def nbrs(i,j):
        res = []
        if i>0: res.append([i-1,j,'U','D'])
        if i<n-1: res.append([i+1,j,'D','U'])
        if j>0: res.append([i,j-1,'L','R'])
        if j<n-1: res.append([i,j+1, 'R','L'])
        return res
    for i in range(n):
        for j in range(n):
            x,y = mat[i][j]
            if x<0:
                for x1, y1,loc,_ in nbrs(i,j):
                    if mat[x1][y1][0]<0:
                        res[i][j] = loc
                        break
            else:
                if x==i and y==j:
                    queue = [[x,y]]
                    res[x][y] = 'X'
                    while len(queue)>0:
                        new_q = []
                        for qx1,qx2 in queue:
                            for nx1, nx2,_, loc in nbrs(qx1, qx2):
                                if res[nx1][nx2]=='A' and mat[qx1][qx2]==mat[nx1][nx2]:
                                    res[nx1][nx2] = loc
                                    new_q.append([nx1, nx2])
                        queue = new_q
                    # BFS Backward

    for i in range(n):
        for j in range(n):
            if res[i][j]=='A':
                print("INVALID")
                return
    print("VALID")
    for li in res:
        print("".join(li))





''' Pythonista fLite 1.1 '''
import sys
from collections import defaultdict, Counter, deque
# from bisect import bisect_left, bisect_right
# from functools import reduce
# import math
input = iter(sys.stdin.buffer.read().decode().splitlines()).__next__
out = []
get_int = lambda: int(input())
get_list = lambda: list(map(int, input().split()))
main()
#[main() for _ in range(int(input()))]
print(*out, sep='\n')
