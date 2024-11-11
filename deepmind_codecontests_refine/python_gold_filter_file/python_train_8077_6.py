x,y=map(int,input().split())
g=1
while True:
	x=x-g
	if x<0:
		print("Vladik")
		break
	y=y-(g+1)
	if y<0:
		print("Valera")
		break
	g=g+2
