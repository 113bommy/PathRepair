for t in range(int(input())):
	n, k = map(int, input().split())
	lev = 1
	b = False
	if n >= 60:
		all_moves = 0
		b = True
	else:
		all_moves = (4 ** n - 1) // 3
	#print(all_moves)
	cnt = 1
	step = 0
	prev_need = 0
	while True:
		need = 2 * cnt - 1
		#print(step, cnt, all_moves, need, k, prev_need)
		if k >= need and step < n:
			k -= need
			all_moves -= need
			cnt *= 2
			step += 1
			prev_need = need
		else:
			if b:
				print('YES', n - step)
				break
			if all_moves < k:
				print('NO')
				break
			#print((4 ** (n - step)) // 3 * need)
			all_moves -= (4 ** (n - step)) // 3 * need
			if all_moves >= k or b:
				print('YES', n - step)
				break
			else:
				print('NO')
				break