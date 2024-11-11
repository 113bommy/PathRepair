for ttt in range(int(input())):
	#n = int(input())
	#l = list(map(int, input().split()))
	n, m, x, y = map(int, input().split())
	l = []
	for i in range(n):
		l.append(input())
	on = x * 2 <= y
	if on:
		xx = 0
		for i in l:
			for j in i:
				xx += j == '.'
		print(xx * x)
	else:
		xx = 0
		for i in l:
			bb = 0
			for j in i:
				if j == '.':
					if bb == 2:
						xx += y
						b = 0
					bb += 1
				else:
					if bb == 2:
						xx += y
						b = 0
					if bb == 1:
						xx += x
						b = 0
			if bb == 1:
				xx += x
			if bb == 2:
				xx += y
		print(xx)