if __name__ == '__main__':
	m, d = map(int, input().split())
	d -= 1
	l = 30
	if (m == 2):
		l = 29
	if (m in {1, 3, 5, 7, 8, 10, 12}):
		l = 31
	res = 1
	#print(l)
	l -= 7-d
	res += l // 7
	l %= 7
	if (l != 0):
		res += 1
	print(res)