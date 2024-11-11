x,y=map(int,input().split())
if x>=y:
	print("1")
else:
	if y%x==0:
		print(y/x)
	else:
		print((y//x)+1)