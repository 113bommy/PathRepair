k=input().split()
n,d=int(k[0]),int(k[1])
b=2*n-d
m=int(input())

for i in range(m):
	k=input().split()
	x,y=int(k[0]),int(k[1])
	if ((y<=(x+d)) and(y >=-(x+d)) and (y >=(x-d)) and (y <=-x+b)):
		print('YES')
	else:
		print('NO') 
