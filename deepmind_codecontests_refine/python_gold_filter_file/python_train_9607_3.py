for _ in range(int(input())):
	rows, cols = map(int, input().split())
	ss = [list(map(int, input())) for _ in range(rows)]
	count = 0
	res = []
	for y in range(rows-1):
		if y%2 and y < rows-2:
			continue
		fixed = False
		for x in range(cols-1):
			if not ss[y][x] and not ss[y+1][x] and x < cols-2:
				fixed = False
				continue
			elif fixed and x < cols - 2:
				fixed = False
				continue
			var = sum(ss[y][x:x+2]) + sum(ss[y+1][x:x+2])
			if var == 0:
				fixed = True
				continue
			if var == 4:
				count += 1
				ss[y+1][x+1] = 0; ss[y][x+1] = 0; ss[y+1][x] = 0
				res.append([y+2, x+2, y+1, x+2, y+2, x+1])
				var = 1
			if var == 1:
				if ss[y][x] == 1:
					cx = x; cy = y;
				elif ss[y][x+1] == 1:
					cx = x+1; cy = y;
				elif ss[y+1][x] == 1:
					cx = x; cy = y+1;
				else:
					cx = x+1; cy = y+1;
				ss[cy][cx] = 0
				ss[y + (1 - (cy-y))][cx] = 1
				ss[y + (1 - (cy-y))][x + (1 - (cx-x))] = 1
				count += 1
				res.append([cy+1, cx+1, y+(1-(cy-y))+1, cx+1, y+(1-(cy-y))+1, x+(1-(cx-x))+1])
				var = 2
			if var == 2:
				if ss[y][x] == 1:
					cx = x; cy = y;
				elif ss[y][x+1] == 1:
					cx = x+1; cy = y;
				elif ss[y+1][x] == 1:
					cx = x; cy = y+1;
				else:
					cx = x+1; cy = y+1;
				cres = []
				for cy2 in range(y, y+2):
					for cx2 in range(x, x+2):
						if ss[cy2][cx2] == 0:
							cres += [cy2+1, cx2+1]
							ss[cy2][cx2] = 1
				count += 1
				ss[cy][cx] = 0
				cres += [cy+1, cx+1]
				res.append(cres)
			count += 1
			cres = []
			for cy in range(y, y+2):
				for cx in range(x, x+2):
					if ss[cy][cx] == 1:
						cres += [cy+1, cx+1]
						ss[cy][cx] = 0
			res.append(cres)
			fixed = True
	print(count)
	#for s in ss: print("".join(map(str, s)))
	for r in res: print(*r)