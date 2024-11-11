n=int(input())
x=list(map(int,input().split()))
y=list(map(int,input().split()))
x=x[1:]
y=y[1:]
z=[]
for i in range (1,n+1):
	z.append(i)
x=set(y)
y=set(y)
z=set(z)
if z==x.union(y):
	print("I become the guy.")
else:
	print("Oh, my keyboard!")