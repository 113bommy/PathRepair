for _ in range(int(input())):
	n=int(input())
	if n==1:print(-1)
	else:
		s=""
		if (n-1)%9==0:s="7"+"2"*(n-2)+"7"
		else:s="2"*(n-1)+"9"
		print(int(s))