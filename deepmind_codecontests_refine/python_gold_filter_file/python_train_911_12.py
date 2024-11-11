import math
#import numpy as np
import queue
from collections import deque,defaultdict
import heapq as hpq
import time
from sys import stdin,setrecursionlimit
#from scipy.sparse.csgraph import dijkstra
#from scipy.sparse import csr_matrix
ipt = stdin.readline
setrecursionlimit(10**7)

def main():
    n = int(ipt())
#    n = 500
    cos = [[min(i,j,n-1-i,n-1-j) for i in range(n)] for j in range(n)]
#    p = [(i//n,i%n) for i in range(n**2)]
    p = [((int(i)-1)//n,(int(i)-1)%n) for i in ipt().split()]
    ans = 0
    q = []
    al = [[True]*n for i in range(n)]

    for px,py in p:
        ans += cos[px][py]
        q.append((px,py,cos[px][py]))
        al[px][py] = False
        while q:
            qx,qy,qc = q.pop()
            if qx != 0 and cos[qx-1][qy] > qc:
                cos[qx-1][qy] = qc
                q.append((qx-1,qy,qc+al[qx-1][qy]))
            if qx != n-1 and cos[qx+1][qy] > qc:
                cos[qx+1][qy] = qc
                q.append((qx+1,qy,qc+al[qx+1][qy]))
            if qy != 0 and cos[qx][qy-1] > qc:
                cos[qx][qy-1] = qc
                q.append((qx,qy-1,qc+al[qx][qy-1]))
            if qy != n-1 and cos[qx][qy+1] > qc:
                cos[qx][qy+1] = qc
                q.append((qx,qy+1,qc+al[qx][qy+1]))

    print(ans)

    return

if __name__ == '__main__':
    main()
