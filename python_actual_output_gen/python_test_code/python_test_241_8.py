# your code goes here
t = input()
t = int(t)

x,y = input().split(':')
x = int(x)
y = int(y)

if(t==24):
	if(x>24):
		x = x%10
		if(y>59):
			y = y%10
	else:
		if(y>59):
			y = y%10
else:
	if(x==0):
		x = 1
		if(y>59):
			y = y%10
	elif(x>12):
		if(x%10==0):
			x=x/10
		else:
			x=x%10
		if(y>59):
			y = y%10
	else:
		if(y>59):
			y = y%10

if(y<10):
	y = str(y)
	y = "0" + y

if(x<10):
	x = str(x)
	x = "0" + x

	

print(x,":",y,sep="")