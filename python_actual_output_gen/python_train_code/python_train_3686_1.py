tests = int(input())
while tests:
	tests -= 1
	l = sorted(list(map(int, input().split())))
	diff = abs(l[2] - l[1])
	if diff > 2:
		print('No')
	else:
		print('Yes')
