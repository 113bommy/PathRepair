for _ in range(int(input())):

	l, r = map(int,input().strip().split())

	if l >= (r+1)/2:
		print("YES")
	else:
		print("NO")
