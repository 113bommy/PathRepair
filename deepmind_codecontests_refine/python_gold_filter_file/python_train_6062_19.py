for nt in range(int(input())):
	n,m=map(int,input().split())
	l=list(map(int,input().split()))
	s=sum(l)
	x=s-l[0]
	print (min(s,m))