t=int(input())
for i in range(t):
	x,y,a,b=map(int,input().split())
	if((x+y)%(a+b)==0):
		print(abs(x-y)//(a+b))
	else:
		print(-1)