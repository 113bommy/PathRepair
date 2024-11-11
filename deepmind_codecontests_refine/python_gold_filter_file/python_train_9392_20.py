n=int(input())
while n>0:
	a,b,c,d=map(int,input().split())
	if a>b:
		s=b
		e=a
	else:
		s=a
		e=b

	x1=c-d
	x2=c+d

	if(x1<s and x2<=s):
		r=e-s
	elif(x1>=s and x2<=e):
		r=(e-s)-(x2-x1)
	elif(x1<s and x2>e):
		r=0
	elif(x1<s and x2>s and x2<=e):
		r=(e-s)-(x2-s)
	elif(x1>=s and x1<e and x2>e):
		r=(e-s)-(e-x1)
	elif(x1>=e and x2>e):
		r=e-s

	print(r)
	n-=1
