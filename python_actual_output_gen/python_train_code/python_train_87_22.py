for _ in range(int(input())):
	n = int(input())
	tw,tr = 0,0
	while n%2 ==0:
		n//=2
		tw+=1
	while n%3 == 0:
		n//=3
		tr+=1
	if n!=1 or tr<tw:
		print(-1)
	else:
		print(tr*2+tw)