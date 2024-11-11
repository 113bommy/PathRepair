n=int(input())
a=list(map(int,input().split()))
x,y=map(int,input().split())
c=0
f=0
for i in range(n):
	c=c+a[i]
	if((c>=x and c<=y) and (sum(a[i+1:])>=x and sum(a[i+1:])<=y)):
		f=1
		break
if(f==1):
	print(i+2)
else:
	print(0)
