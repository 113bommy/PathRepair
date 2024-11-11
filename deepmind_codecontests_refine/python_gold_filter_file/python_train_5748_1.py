import math
def getFirstSetBitPos(n):
	return math.log2(n & -n) + 1

def find_div(x):
	ls=[]
	for i in range(2,int(x**0.5)+1):
		if x%i==0:
			ls.append(i)
			if i!=x//i:
				ls.append(x//i)

	return sorted(ls)
from collections import Counter
#for _ in range(1):
n = int(input())
	#arr = list(map(int, input().split()))
ar= [(int(x),i) for i, x in enumerate(input().split())]
arr = sorted(ar, key=lambda x: (x[0], -1*x[1]))
m=int(input())
#print(arr)
for i in  range(m):
	k, pos = map(int, input().split())
	ls = sorted(arr[-k:], key=lambda x:x[1])
	#print(ls)
	print(ls[pos-1][0])










