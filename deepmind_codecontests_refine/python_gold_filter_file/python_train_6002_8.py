x,y=map(int,input().split())
z=y%((x*(x+1))//2)
for i in range(1,x+1):
	if i>z or z==0:
		print(z)
		break
	else:
		z=z-i
#author:SK__Shanto__㋛
#code__define__your__smartness