for _ in range(int(input())):

	l, r = map(int,input().strip().split())

	if l//2 >= (r+1):
		print("YES")
	else:
		print("NO")
