from sys import stdin
import math
from collections import defaultdict,deque
import bisect



#stdin = open('input.txt','r')



I = stdin.readline





n = int(I())
s=I().rstrip()
arr = defaultdict(lambda : [])
for i in range(len(s)):
	arr[s[i]].append(i+1)
#print(arr)
for i in range(int(I())):
	t=I().rstrip()
	ans=-1
	key=defaultdict(lambda : 0)
	for i in t:
		key[i]+=1
	for i in key:
		ans=max(ans,arr[i][key[i]-1])

	print(ans)
	





