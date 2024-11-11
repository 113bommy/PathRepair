n,d=map(int,input().split())
a=list(map(int,input().split()))
m=int(input())
if m==n:
	print(sum(a)) 
elif m>n:
	print(-m*d+n*d+sum(a))
else:
	a.sort()
	print(sum(a[:m]))
