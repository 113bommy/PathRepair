m,d=map(int,input().split())
a={1,3,5,7,8,10,12}
if m==2:
	if d==1:
		print(4)
	else:
		print(5)	
elif m in a:
	if 	d>4:
		print(6)
	else:
		print(5)
else: #30
	if d==7:
		print(6)
	else:
		print(5)