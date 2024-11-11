for _ in range(int(input())):
	n=int(input())
	l=list(map(int,input().split()))
	f=0
	c=l.count(0)
	if (sum(l) + c==0):
		print(c+1)
	else:
		print(f)