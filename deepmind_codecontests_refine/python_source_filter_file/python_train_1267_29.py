'''input
10 2 3
10 9 6 7 8 3 2 1 4 5

'''
import sys
from collections import defaultdict as dd

mod=10**9+7

def ri(flag=0):
	if flag==0:
		return [int(i) for i in sys.stdin.readline().split()]
	else:
		return int(sys.stdin.readline())


n,x,y = ri()

a= ri()

ans =0
for i in range(0,n):
	status=0
	for j in range(max(0,i-x), min(n,i+y+1)):
		#print(a[i],a[j],i,j)
		if i!=j and a[i]> a[j]:
			status=1
	if status==0:
		ans=1
		print(i+1)
		#break

