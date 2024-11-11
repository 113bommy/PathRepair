q=int(input())
for i in range(q):
	l,r,d = map(int, input().split())
	if d<l or d>r:
		print(r)
	else:
		print((r//d)+d)