for _ in range(int(input())):
	n=int(input())
	if n==1:print(-1)
	else:
		s=""
		if (n-1)%3==0:s="5"*(n-1)+"7"
		else:s="5"*(n-1)+"3"
		print(int(s))