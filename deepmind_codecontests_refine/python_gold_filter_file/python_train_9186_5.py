import sys
import math
from collections import defaultdict,deque
import heapq
n=int(sys.stdin.readline())
arr=list(map(int,sys.stdin.readline().split()))
ans=0
for i in range(n):
	for j in range(i,n):
		for k in range(j,n):
			ans=max(ans,arr[i]|arr[j]|arr[k])
print(ans)