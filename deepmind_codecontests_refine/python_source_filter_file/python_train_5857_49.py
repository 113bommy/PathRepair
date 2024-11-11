
t=int(input())
for i in range(t):
	n,r = map(int, input().split())
	x = min(n,r-1)
	x = x*(x+1)//2
	if r>=n:
		x+=1
	print(x)