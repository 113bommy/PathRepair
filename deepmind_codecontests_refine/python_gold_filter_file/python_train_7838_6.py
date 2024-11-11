a=int(input())
b=list(map(int,input().split()))
b.sort()
x=len(b)
if sum(b)<a:
	print('-1')
elif a==0:
	print('0')
else:
	
	while x>0:
		x1=b[x-1:]
		y1=sum(x1)
	#	print(x1,y1)
		if sum(x1)>=a:
			break
		x-=1
	print(len(x1))