n=97
def c(i,j,k):print('<',i,j,k)
def a(i,j,k):print('+',i,j,k)
def d(x,i,j):
	for t in range(30):
		a(j+t-1,j+t-1,j+t)
		a(j+t,n,j+t)
		for s in range(j+t,j+29):a(s,s,s+1)
		c(j+29,x,i+t)
		a(j+t-1,j+t-1,j+t)
		a(j+t,i+t,j+t)
print(3932)
a(0,1,n)
c(2,n,n)
a(0,n,3)
a(1,n,4)
d(3,5,36)
d(4,36,67)
for t in range(59):
	a(2,2,2)
	for s in range(t+1):
		if t-30<s<30:a(5+t-s,36+s,98);c(n,98,99);a(2,99,2)