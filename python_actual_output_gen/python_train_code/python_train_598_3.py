'''a,b=map(int,input().split())
x=pow(2,b)-1
y=x
for i in range(0,a-1):
	y=(y*x)%(1e9+7)
print(int(y))'''
n=int(input())
l=[]
for i in range(0,n):
	l.append([])
for i in range(0,n):
	if i%2==0:
		for j in range(0,n):
			l[j].append(i*n+j+1)
	else:
		for j in range(0,n):
			l[j].append(i*(n+1)-j)
for i in range(0,n):
	for j in l[i]:
		print(j,end=' ')
	print()