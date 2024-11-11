n = int(input())
l = []
for i in range(n):
	l.append(list(map(int, input().split())))


def supercentral(x: list):
	left, right, upper, lower = 0,0,0,0
	for i in l:
		if (x[0] > i[0] and x[1] == i[1]):
			right += 1
		if (x[0] < i[0] and x[1] == i[1]):
			left += 1
		if (x[0] == i[0] and x[1] < i[1]):
			upper += 1
		if (x[0] == i[0] and x[1] > i[1]):
			lower += 1
	if min(left, right, upper, lower) != 0:
		return True
	else:
		return False


print(len(list(filter(supercentral, l))))