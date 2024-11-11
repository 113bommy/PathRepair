for _ in range(int(input())):
	x,y=map(int,input().split())
	a=list(map(int,input().split()))
	for i in range(1,x):
		a[0]=a[0]+min((y//i),a[i])
		y=y-min((y//i),a[i])*(y//i)
		if y<=0:
			break
	print(a[0])
#author:SK__Shanto__㋛
#code__define__your__smartness