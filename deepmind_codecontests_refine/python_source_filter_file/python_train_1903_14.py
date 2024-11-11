from collections import *

for T in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))
	
	m = sorted([x for i, x in enumerate(a) if b[i] == 0])
	
	j = 0
	for i,x in enumerate(a):
		if(b[i] == 0):
			a[i] = m[j]
			j += 1
	
	print(" ".join(map(str, a)))
		
	
