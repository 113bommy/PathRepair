for _ in range(int(input())):
	s, i, e = map(int, input().split())
	if e == 0 :
		if s > i:
			print(1)
			continue
		else:
			print(0)
			continue
	if s+e > i:
		invest_x = (i-s+e)//2
		startFrom = invest_x+1
		if invest_x < 0:
			print(e)
		else:
			print(e - startFrom + 1)
	else:
		print(0)