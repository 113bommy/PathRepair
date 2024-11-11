n=int(input())
a=[]
b=[]
for i in range(n):
	ai=1
	a.append(ai)
if n==1:
	print(1)
else:
	for i in range(n-1):
		for j in range(n-1):
			a[j+1]=a[j]+a[j+1]
			b.append(a[j+1])
		print(b[-1])