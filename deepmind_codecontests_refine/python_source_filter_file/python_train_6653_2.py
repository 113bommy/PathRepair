while 1:
	x,y = list(map(int,input()split()))
	if x == 0:
		break

	pp = [1,-1,0,0]
	qq = [0,0,1,-1]
	m = []
	for i in range(y):
		m.append(list(input()))
		if '@' in m[-1]:
			ss = m[-1].index('@')
			tt = i
	cnt = 0

	def move (cx,cy):
		global cnt
		if cy >= y or cy < 0 or cx >= x or cx < 0:
			return
		if m[cy][cx] = '.'v or  m[cy][cx] = '@'
			cnt += 1
			m[cy][cx] = '0'
			for i in range(4):
				move(cx + pp[i],cy + qq[i])
	move(ss,tt)
	print(cnt)

