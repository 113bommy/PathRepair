def f(a,x,y):
	if(x>=a or x<=0-a or y%a==0):
		print(-1)
		return
	if(y<a):
		if(x<a/2 and x+a/2>0):
			print(1)
		else:
			print(-1)
		return
	y-=a
	t=int(y/(a))
	if(t%2==0):
		if(x<a/2 and x+a/2>0):
			print(int(2+t/2*3))
		else:
			print(-1)
		return
	else:
		t-=1
		val=int(2+t/2*3)
		if(x==0 or x>a or x+a<0):
			print(-1)
		elif x>0:
			print(val+1)
		else:
			print(val+2)
		return
a,x,y=map(int,input().split())
f(a,x,y)