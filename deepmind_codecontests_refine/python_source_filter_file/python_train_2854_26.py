def zip_sorted(a,b):

	# sorted  by a
	a,b = zip(*sorted(zip(a,b)))
	# sorted by b
	sorted(zip(a, b), key=lambda x: x[1])

	return a,b

import sys
input = sys.stdin.readline
I = lambda : list(map(int,input().split()))
S = lambda : list(map(str,input().split()))


n,=I()
a   = I()

a_i1 = a[0]
longest = 1
present = 1
for i in range(1,len(a)):
	if present==1:
		present = present + 1
	else:
		if a[i]==(a_i1+a_i2):
			present = present + 1
		else:
			if present>=longest:
				longest = present
			present = 1
	a_i2 = a_i1
	a_i1 = a[i] 

	if i==len(a)-1:

		if present>=longest:
			longest = present

print(longest)

'''
for i in range(n):
for j in range(n):
for k1 in range(len(a)):
for k2 in range(len(a)):
for k3 in range(len(a)):

'''