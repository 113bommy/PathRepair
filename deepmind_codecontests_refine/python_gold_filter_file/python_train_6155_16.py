n=int(input())
x,y=map(int,input().split())
k=(((x-1)^2)+((y-1)^2))
l=(((n-x)^2)+((n-y)^2))
if(k>l):
	print("black")
else:
	print("white")
