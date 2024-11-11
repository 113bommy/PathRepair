from math import *
p,q=map(int,input().split())
s=[int(n) for n in input().split()]
z=[int(n) for n in input().split()]
if p<q:
	print('0/1')
elif p>q:	
	if s[0]/z[0]>0:
		print('Infinity')
	else:
		print('-Infinity')
	
elif p==q:
	x=(s[0]/z[0])
	if x!=0:
		k=1
		while 1:
			if ceil(k*x)==floor(k*x):
				break
			else:
				k+=1
		r=int(x*k)
		print('{}/{}'.format(r,k))
	else:
		print('0/1')
			