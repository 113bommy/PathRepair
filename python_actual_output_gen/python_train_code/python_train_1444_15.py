n=int(input())
f=0
for i in range(n):
	a=input()
	b=sorted(a)
	for j in range(len(a)-1):
		if ord(b[j])+1==ord(b[j+1]):
			continue
		else:
			f=1
			break
	if f==1:
		print('No')
	else:
		print('Yes')