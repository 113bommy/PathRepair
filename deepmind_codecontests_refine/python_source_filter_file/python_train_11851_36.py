'''
自宅用PCでの解答
'''
import math
#import numpy as np
import itertools
import queue
import bisect
from collections import deque,defaultdict
import heapq as hpq
from sys import stdin,setrecursionlimit
#from scipy.sparse.csgraph import dijkstra
#from scipy.sparse import csr_matrix
ipt = stdin.readline
setrecursionlimit(10**7)
mod = 10**9+7
dir = [(-1,0),(0,-1),(1,0),(0,1)]
alp = "abcdefghijklmnopqrstuvwxyz"

def main():
    n = int(ipt())
#    n = 20000
    if n == 3:
        print("2 3 25")
        exit()
    elif n == 4:
        print("2 5 20 63")
        exit()
    tn = (n//8)*8
    sm = 0
    nm = 0
    ans = []
    la = 0
    for i in range(1,30001):
        if i%2 == 0 or i%3 == 0:
            ans.append(i)
            sm += i
            nm += 1
        if nm == tn:
            if ans:
                la = ans[-1]
            break

    if n%8 == 0:
        pass
    elif n%8 == 1:
        ans.append(la+6)
    elif n%8 == 2:
        ans.append(la+2)
        ans.append(la+4)
    elif n%8 == 3:
        ans.append(la+2)
        ans.append(la+4)
        ans.append(la+6)
    elif n%8 == 4:
        ans.append(la+2)
        ans.append(la+4)
        ans.append(la+6)
        ans.append(la+12)
    elif n%8 == 5:
        ans.append(la+2)
        ans.append(la+3)
        ans.append(la+4)
        ans.append(la+6)
        ans.append(la+9)
    elif n%8 == 6:
        ans.append(la+2)
        ans.append(la+3)
        ans.append(la+4)
        ans.append(la+6)
        ans.append(la+8)
        ans.append(la+10)
    elif n%8 == 7:
        ans.append(la+2)
        ans.append(la+3)
        ans.append(la+4)
        ans.append(la+6)
        ans.append(la+8)
        ans.append(la+10)
        ans.append(la+12)


    print(" ".join(map(str,ans)))


    return None

if __name__ == '__main__':
    main()
