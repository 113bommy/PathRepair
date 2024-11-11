while True:
	H, W = list(map(int, input().split()))
	if H == 0 and W == 0:
		break
	else:
		a = list(input() for i in range(H))
		visitedlist = []
		h = 0
		w = 0
		while True:
			if (h, w) not in visitedlist:
				visitedlist.append([h, w])
				if a[h][w] == '>':
					w += 1
				if a[h][w] == '<':
					w -= 1
				if a[h][w] == '^':
					h -= 1
				if a[h][w] == 'v':
					h += 1
				if a[h][w] == '.':
					print(w, h)
					break
			else:
				print('LOOP')
				break
				