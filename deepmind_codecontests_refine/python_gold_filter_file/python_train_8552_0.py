n=int(input())
a=list(map(int,input().split()))
l=set(a)
a.sort()
if len(l)==1:
	print(-1)
else:
	print(*a)