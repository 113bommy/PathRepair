n,k = map(int,input().split())
c=0
for i in range(n):
	a,b = map(str,input().split())
	b = int(b)
	if a == '+':
		k = k + b
	elif a == '-':
		if k-b>0:
			k = k - b
		else:
			c+=1
print(k,c)
	