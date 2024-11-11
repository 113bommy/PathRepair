for case in range(int(input())):
	A,B = map(int,input().split())
	l = 1
	while(int("9"*l) < B):
		l+=1
	l-=1
	print(A*l)