for _ in range(int(input())):
	n=int(input())
	l=list(map(int,input().split()))
	s=sum(l)
	# print(s, s%n)
	a=s%n
	b=n-a
	print(a*b)