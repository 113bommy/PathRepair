t = int(input())
for j in range(t):
	n,x = list(map(int,input().split()))
	a = list(sorted(list(map(int,input().split()))))
	j = 0
	for i in range(1,200):
		if i in a:
			j += 1
		else:
			if x >= 1:
				j += 1
				x -= 1
			else:
				break
	print(j)