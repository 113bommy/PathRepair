import sys

pin = sys.stdin.readline
pout = sys.stdout.write


a=int(pin())
b=int(pin())
c=int(pin())
d=int(pin())
e=int(pin())
f=int(pin())
first=0
second=0
third=0
fourth=0
fifth=0
sixth=0
if min(a,d)==d:
	first=d*e
	j=0
	second=min(b,c,j)*f
if min(a,d)==a:
	third=a*e
	x=d-a
	fourth=min(b,c,x)*f
mine=min(b,c,d)
fifth=mine*f
d=d-mine
if d<a:
	sixth=d*e+fifth
else:
	sixth=a*e+fifth	
print(max(first,second,third,fourth,fifth,sixth))	