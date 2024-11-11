a,b=map(int,input().split())
n=int(input())
t=[]
for i in range(n):
	x,y,v=map(int,input().split())
	t=[pow((a-x)**2+(b-y)**2,0.5)/v]
t.sort()
print("%.8f" % t[0])
