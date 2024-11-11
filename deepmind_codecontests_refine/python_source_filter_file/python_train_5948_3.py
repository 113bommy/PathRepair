n=int(input())
l=list(input())
c=0
for i in range(n):
	c+=i
	if c>=n:
		break
	else:
		print(l[c])