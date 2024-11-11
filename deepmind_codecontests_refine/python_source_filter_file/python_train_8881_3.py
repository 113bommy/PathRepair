n=int(input())
for i in range(n):
	x=int(input())
	a=list(map(int,input().split()))
	b=list(map(int,input().split()))
	l1=[]
	l2=[]
	if sum(a)!=sum(b):
		print(-1)
	else:
		for j in range(x):
			if a[j]>b[j]:
				l1.extend([j+1]*(a[j]-b[j]))
			elif b[j]>a[j]:
				l2.extend([j+1]*(b[j]-a[j]))
		if len(l1)==0:
			print(0)
		else:
			print(l2)
			for k in range(len(l2)):
				print(l1[k],l2[k])	