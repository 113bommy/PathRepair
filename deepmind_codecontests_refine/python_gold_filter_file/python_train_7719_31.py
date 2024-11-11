import sys
n, m = [int(x) for x in input().split()]
out=0
if(float(m)<=n/2 and float(m)>0): 
	out=m 
elif(float(m)>n/2):
	out=n-m
elif(m==0):
	out=1

print(out)