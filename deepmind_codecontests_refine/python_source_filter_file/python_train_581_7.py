import itertools

def sump(a : list, p : list):
	s = 0
	for i in range(0, 3):
		if p.count(i) == 0:
			s  = s + a[i]
	for i in range(3, 6):
		if p.count(i) == 0:
			s = s - a[i]
	return s

def diffsum(p:list):
	mins = 0
	maxs = 0
	for i in p:
		if i <= 2:
			maxs = maxs + 9
		else:
			mins = mins - 9			
			
	return [mins, maxs]

def solve():
	s = input().replace("\r\n", "")
	a = []
	for ai in s:
		a.append(int(ai))

	p = [0, 1, 2, 3, 4, 5]
	if sump(a, []) == 0:
		print("0")
		return
	for i in range(1, 7):
		for pi in itertools.combinations(p, i):
			s = -sump(a, pi)
			rs = diffsum(pi)
			if (s >= rs[0]) and (s <= rs[1]):
				print(i)
				return
	print("error")

try:
	while True:
		solve()
except Exception as e:
	print(e)
	exit(0)

#solve()