[x,y,z] = list(map(int,input().split()))
if(x==y):
	if(z!=0):
		print("?")
	else:
		print("0")
elif(x>y):
	if(z<(x-y)):
		print("+")
	else:
		print("?")
else:
	if(z<(y-x)):
		print("-")
	else:
		print("?")

