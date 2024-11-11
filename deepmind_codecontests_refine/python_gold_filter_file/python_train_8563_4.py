def f(x,b):
	m=0
	for n in range(10000):
		m+=x%b
		u=int(x/b)
	#	print(x%b)
		x=u
		if x<b:
			m+=x%b
			break
	return m
#print(f(5,3))
def g(x,y):
	p=1
	m=int((x+y-abs(x-y))/2)
	for n in range(2,m+1):
		if x%n==0 and y%n==0:
		#	print(n)
			p=n
		else:
			p=p
	return p
m=0
#print(g(9,6))
x=int(input())
for n in range(2,x):
	m+=f(x,n)
print("{}/{}".format(int(m/g(m,x-2)),int((x-2)/g(m,x-2))))

