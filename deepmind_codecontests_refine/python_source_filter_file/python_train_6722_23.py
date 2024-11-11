c=[]
import math
n=int(input())
for i in range(1,n+1):
	if n%i==0:
		c.append(i)
min=9999999
a=b=math.sqrt(n)
for i in range(1,len(c)):
	m=c[i]-c[i-1]
	if m<min and c[i]*c[i-1]==n:
		a=c[i]
		b=c[i-1]
		min=m
print(a,b)
