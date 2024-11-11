n=int(input())
x=list(map(int,input().split()))
a,b=list(map(int,input().split()))

c=0
for i in range(1,n+1):
	if a!=b:
		c+=x[a-1]
	else:
		print(c)
		break