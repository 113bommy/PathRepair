x,y,z=map(int,input().split());a,b,c=map(int,input().split())
if c>=x and (a+b)>=y and (a+b+c-x-y)>=z:
	print("YES")
else:
	print('NO')