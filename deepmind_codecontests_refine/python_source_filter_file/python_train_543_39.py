t=int(input());
for i in range(t):
	n=int(input())
	s=0
	while(n!=-1):
		s+=(n+2*(n-1)+n-2)*(n/2)
		n-=2	
	print(s)