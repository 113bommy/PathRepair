y,z=map(int,input().split())
y,n=int("1"+"0"*(y-1)),int("9"*y)
for i in range(y,n):
	if i>0 and i%z==0:
		print(i)
		break
	else:
		pass
else:
	print("-1")



