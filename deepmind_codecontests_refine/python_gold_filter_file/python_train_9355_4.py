import sys
a=[int(i)for i in sys.stdin]

b=[]

for j in a:
	if j == 0:
		print(b.pop())
	else:
		b.append(j)

