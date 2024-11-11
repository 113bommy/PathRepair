t = int(input())
for i in range(t):
	st = str(input().strip())
	r = int(st[0])
	n = len(st)
	cost = (r-1)*10 
	cost += (n*(n-1))//2
	print(cost)