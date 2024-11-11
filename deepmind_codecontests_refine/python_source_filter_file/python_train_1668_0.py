x,y=map(int,input().split())
while x%y!=0:
	tmp=y
	y=x%y
	x=tmp
print(y,end='')

