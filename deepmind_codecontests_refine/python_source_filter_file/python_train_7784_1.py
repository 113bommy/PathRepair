from collections import *
n,m = map(int,input().split())
d = dict()
i,j = 1,n
for y in range(m):
	if(n%2 == 0 and i == (m+1)//2):
		i += 1
	print(i,j)
	i += 1
	j -= 1
