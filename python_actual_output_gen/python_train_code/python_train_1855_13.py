p,n=map(int,input().split())
l=[]
for i in range(n):
	x=int(input())
	s=x%p
	if s in l:
		print(i+1)
	else:
		l.append(s)

if len(l)==n:
	print(-1)