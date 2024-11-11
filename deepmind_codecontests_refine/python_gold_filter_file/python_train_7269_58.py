n,y = map(int,input().split())

y = y//1000

for a in range(n+1):
	for b in range(0,n+1-a):
		c = n - (a+b)
		if y == 10*a + 5*b + c:
			print(a,b,c)
			exit()


print("-1 -1 -1")