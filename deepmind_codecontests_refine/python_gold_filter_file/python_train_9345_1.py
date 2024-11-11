n=97
p=print
r=range
def c(i,j,k):p('<',i,j,k)
def a(i,j,k=0):p('+',i,j,max(i,k))
def b(i):a(i,i,i+1)
def d(x,i,j):
	for t in r(30):
		b(j+t-1);a(j+t,n)
		for s in r(j+t,j+29):b(s)
		c(j+29,x,i+t);b(j+t-1);a(j+t,i+t)
p(3933)
a(0,1,n)
c(2,n,n)
a(0,n,3)
a(1,n,4)
d(3,5,36)
d(4,36,67)
for t in r(59):
	a(2,2)
	for s in r(t+1):
		if t-30<s<30:a(5+t-s,36+s,98);c(n,98,99);a(2,99)