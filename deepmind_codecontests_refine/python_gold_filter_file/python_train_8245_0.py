t=int(input())
from math import *
def fun(a):
	return (a*(a+1))//2
for tt in range(t):
	a,b=map(int,input().split())
	d=abs(a-b)
	if d==0:
		print(0)
		continue
	q=int(sqrt(2*d))
	l=[]
	num=[q-2,q-1,q,q+1,q+2]
	for i in range(q-2,q+3):
		l.append(fun(i))
	for i in range(4):
		if l[i]==d:
			print(num[i])
			break
		elif l[i]<d<l[i+1]:
			k=d-l[i]
			tem=num[i]
			# m=l[i+1]-d
			# if k<m:
			# 	tem=num[i]
			# else:
			# 	k=m
			# 	tem=num[i+1]
			if tem%2==0:
				num1=tem+1
				num2=tem+3
			else:
				num1=tem+2
				num2=tem+1
			if k%2==0:
				print(num2)
			else:
				print(num1)
	if l[4]==d:
		print(num[4])



