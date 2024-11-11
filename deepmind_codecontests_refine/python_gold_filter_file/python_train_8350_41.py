for _ in range(int(input())):
	l=list(map(int, input().split()))
	h=l[0]
	m=l[1]
	ans=(24-h-1)*60+(60-m)
	print(ans)