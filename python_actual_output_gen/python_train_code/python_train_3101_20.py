x,y = map(int,input().split())
if(y==0 or x<y-1):
	print("No")
else:
	r = x-y+1
	if(r==0):
		print("Yes")
	if(r>0 and r%2==0):
		if(x>1):
			print("Yes")
		else:
			print("No")
	else:
		print("No")