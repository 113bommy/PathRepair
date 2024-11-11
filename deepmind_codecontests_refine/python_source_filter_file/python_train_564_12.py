s=input()
t=input()
if len(s)==len(t):
	x=list(s)
	y=list(t)
	x.sort()
	y.sort()
	n=len(s)
	ntree=False
	for i in range(n):
		if x[i]!=y[i]:
			ntree=True
			break
			
	if ntree:
		print("need tree")
	else:
		print("array")
else:
	x=list(s)
	y=list(t)
	n=len(x)
	m=len(y)
	j=0
	nboth=False
	for i in range(m):
		while j<n:
			if x[j]!=y[i]:
				j+=1
			else:
				break
		if j==n:
			nboth=True
			break
		j+=1
	if not nboth:
		print("automaton")
	else:
		x.sort()
		y.sort()
		ntree=False
		j=0
		for i in range(m):
			while j<n:
				if x[j]!=y[i]:
					j+=1
				else:
					break
			if j==n:
				ntree=True
				break
		if not ntree:
			print("both")
		else:
			print("need tree")
			