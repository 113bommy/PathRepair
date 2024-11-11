import logging
logging.basicConfig(level=logging.INFO)

def readGenerator(transform):
	while (True):
		n=0
		tmp=tuple(map(lambda x:transform(x), input().split()))
		m=len(tmp)
		while (n<m):
			yield(tmp[n])
			n+=1
	
readint=readGenerator(lambda x:int(x))
A,B,C=next(readint),next(readint),next(readint)

def exGCD(x,y):
	if (y==0): return [x,1,0]
	tmp=exGCD(y,x%y)
	return [tmp[0], tmp[2], tmp[1]-x//y*tmp[2]]

def solve(L,R,q):
	if (q<0): return solve(-R,-L,-q)
	b=R//q
	a=-(-L//q)
	return [a,b]

L=int(5*1e18)

def work(A,B,C):
	tmp=exGCD(A,B)
	d,u,v=tmp[0],tmp[1],tmp[2]
	p=A//d
	q=B//d
	if (C%d!=0):
		print(-1)
		return 0
	x0=-u*C//d
	y0=-v*C//d
	rx,ry=[],[]
	if (q!=0): rx=solve(-L-x0,L-x0,q)
	if (p!=0): ry=solve(y0-L,L+y0,p)
	if (p==0):
		n=rx[0]
	elif (q==0):
		n=ry[0]
	else:
		a=max(rx[0],ry[0])
		b=min(rx[1],ry[1])
		if (a>b):
			print(-1)
			return 0
		n=a
	x=x0+n*q
	y=y0-n*p
	print(x,y)
	print(A*x+B*y)
	return 1

work(A,B,C)

