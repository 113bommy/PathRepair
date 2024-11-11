n=int(input())
a=[]
sum=0
for i in range(n):
	a.append(input().split())
for x in range(n):
	for y in range(n):
		if x==y:
			sum+=int(a[x][y])
		elif x==n-(y+1):
			sum+=int(a[x][y])	
		elif x==int(n/2):
			sum+=int(a[x][y])
		elif y==int(n/2):
			sum+=int(a[x][y])	
print(sum)				