l = [int(x) for x in input().split()]
l.sort()

if sum(l[:-1]) == l[-1] or l[0]+l[-1] == l[1]+l[2]:
	print('YES')
else:
	print('NO')