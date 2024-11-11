T = int(input())

for t in range(T):
	a,b,c,m=map(int,input().split())
	d=a+b+c-3
	e=max([a,b,c]) - (a+b+c-max([a,b,c]))
	if (m >= e) and (m <= d):
		print("YES")
	else:
		print("NO")
	