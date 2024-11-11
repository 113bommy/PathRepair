n=int(input())
x=n//4
if x%4==0:
	x-=1
if x%2==1:
	x=0
print(x)