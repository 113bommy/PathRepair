n=int(input())
li=input().split()
m=len(li)
x=0
y=0
if m==n:
	p=li.count('L')
	q=li.count('R')
	for i in range(p):
		x=x+1	
	for i in range(q):
		y=y+1
	z=x+y+1
	print(z)