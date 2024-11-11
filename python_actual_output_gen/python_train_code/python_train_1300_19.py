t=int(input())
while t>0:
	t-=1
	n=int(input())
	l=list(map(int,input().split()))
	s=sum(l)
	if n*(s//n)>=s:
	    print(n)
	else:
	    print(n+1)