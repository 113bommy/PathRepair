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

def main():
    n = int(ipt())
#    n = 10**5
    ls_by = [[] for i in range(n+1)]
    for i in range(2,n+1):
        a = int(ipt())
        ls_by[a].append(i)
    def dpt(k):
        st = []
        for i in ls_by[k]:
            st.append(dpt(i)+1)
        st.sort(reverse=True)
        ma = 0
        for i,si in enumerate(st):
            if si+i > ma:
                ma = si+i
        return ma

    print(dpt(1))


    return None

if __name__ == '__main__':
    main()
