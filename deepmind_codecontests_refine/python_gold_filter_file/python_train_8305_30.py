import sys

read = sys.stdin.buffer.read
input = sys.stdin.buffer.readline
inputs = sys.stdin.buffer.readlines


# rstrip().decode('utf-8')
# INF=float("inf")
#MOD=10**9+7
# sys.setrecursionlimit(2147483647)
# import math
#import numpy as np
# import operator
import bisect
# from heapq import heapify,heappop,heappush
#from math import gcd
# from fractions import gcd
#from collections import deque
#from collections import defaultdict
# from collections import Counter
#from itertools import accumulate
# from itertools import groupby
# from itertools import permutations
# from itertools import combinations
# from scipy.sparse import csr_matrix
# from scipy.sparse.csgraph import floyd_warshall
# from scipy.sparse.csgraph import csgraph_from_dense
# from scipy.sparse.csgraph import dijkstra
# map(int,input().split())


def main():
	n,*p=map(int,read().split())
	H=[0,0,n+1,n+1]
	pidx=[0]*(n+1)
	for i in range(n):
		pidx[p[i]]=i+1
	
	pidx.reverse()
	
	
	ans=0
	for i in pidx:
		I=bisect.bisect_left(H,i)
		ans+=p[i-1]*((H[I-1]-H[I-2])*(H[I]-i)+(H[I+1]-H[I])*(i-H[I-1]))
		H.insert(I,i)
	print(ans)
	
	
if __name__ == "__main__":
		main()
