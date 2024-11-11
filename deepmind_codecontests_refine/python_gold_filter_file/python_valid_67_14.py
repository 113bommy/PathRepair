n=int(input())
for i in range(n):
	a,b,c=map(int,input().split())
	if abs(a-b)*2<max(a,b,c):
		print(-1)
	elif c>abs(a-b):
		print(abs(c-abs(a-b)))
	else:
		print(abs(c+abs(a-b)))