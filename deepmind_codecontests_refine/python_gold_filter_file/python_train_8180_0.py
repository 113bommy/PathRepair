n = int(input())
p = lambda a,b: print(a+1,b+1)
if n % 4 > 1:
	print("NO")
else:
	print("YES")
	for i in range(n%4,n,4):
		for x in range(2):
			for j in range(i): p(j,i+2*x)
			p(i+2*x,i+2*x+1)
			for j in range(i,0,-1): p(j-1,i+2*x+1)
		p(i,i+3)
		p(i+1,i+2)
		p(i,i+2)
		p(i+1,i+3)