def pos(a, b):
	if a == b:
		return 'g'
	if a > b:
		return 'u'
	return 'd'

if __name__ == '__main__':
	n = int(input())
	moves = input()
	l = 0
	r = 0
	k = 'u'
	coin = 0
	for m in moves:
		x = l
		y = r
		if m == 'R':
			x += 1
		if m == 'U':
			y += 1
		if pos(x, y) != 'g' and pos(x, y) != k:
			coin += 1
			k = pos(x, y)
		l = x
		r = y
	if moves[0] == 'U':
		coin -= 1
	print(coin)
