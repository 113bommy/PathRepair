t = int(input())
for i in range(t):
	n,m,x1,y1,x2,y2 = map(int,input().split(' '))
	print(n*m-2*((n-abs(x1-x2))*(m-abs(y1-y2)))+(min(0,(n-2*(n-abs(x1-x2)))*min(0,m-2*m-abs(y1-y2)))))