from math import *

t=int(input())

while t>0:
	a=[int(x) for x in input().split()]
	n=a[0]
	s=a[1]
	k=a[2]

	k_list=[int(x) for x in input().split()]

	for i in range(k+1):
		if k_list.count(s+i)==0 and s+i<n:
			print(i)
			break
		if k_list.count(s-i)==0 and s-i>0:
			print(i)
			break

	t-=1