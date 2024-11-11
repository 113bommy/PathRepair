n=int(input())
l=[]
a=[]
x=2
if n==2:
	print("2")
	exit()
else:
	for i in range(2,n+1):
		a.append(x)
		x+=i
		if x>n:
			x-=n
print(a)