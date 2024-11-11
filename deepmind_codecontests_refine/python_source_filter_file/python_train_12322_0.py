# your code goes here
n=int(input())
def s(x):
    return sum(int(i) for i in str(x))
x=int(n**0.5)
d=0
while x>=0 and d<=50:
	if(x*x+s(x)*x==n):
	#	print(x)
		break
	d+=1
	x-=1
if d==50:
	x=-1
print(x)	