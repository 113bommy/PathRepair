# import sys
# sys.stdin=open('input.in','r')
# sys.stdout=open('output.out','w')
for x in range(int(input())):
	a,b,c,d=map(int,input().strip().split()[:4])
	if b==0:
		print(abs(c-d))
	else:
		if c>d:
			c+=b
			if c>a:
				k=c-a
				c-=k
				b=k
				d-=k
				if d<=1:
					d+=abs(1-d)
					print(abs(c-d))
				else:
					print(abs(c-d))
			else:
				print(abs(c-d))
		else:
			d+=b
			if d>a:
				k=d-a
				d=a
				b=k
				c-=k
				if c<=0:
					c+=abs(1-c)
					print(abs(c-d))
				else:
					print(abs(c-d))
			else:
				print(abs(c-d))