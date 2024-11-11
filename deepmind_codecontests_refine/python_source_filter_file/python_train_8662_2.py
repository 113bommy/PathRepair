def calculate(ar, num):
	s = 0
	for x in range(len(ar)):
		if(num >= ar[x][0]):
			num -= ar[x][0]
		else:
			s += (1 if ar[x][1] else 2)
	return s

def calculate1(ar, num):
	s = calculate(ar, num)
	ar1 = []
	for x in range(len(ar)):
		if(ar[x][1]):
			ar1.append(x)
	if(len(ar1) >= 1):
		tmp = ar[ar1[0]]
		ar = ar[:ar1[0]] + ar[ar1[0] + 1:]
		s = min(s, calculate(ar, num) + 1)
		ar = ar[:ar1[0]] + [tmp] + ar[ar1[0]:]
	if(len(ar1) == 2):
		ar = ar[:ar1[1]] + ar[ar1[1] + 1:]
		s = min(s, calculate(ar, num) + 1)
		ar = ar[:ar1[0]] + ar[ar1[0] + 1:]
		s = min(s, calculate(ar, num) + 2)
	return s



n = int(input())
p = list(map(int, input().split(" ")))
ar = [False] * (n + 1)
for x in p:
	if(x != 0):
		ar[x] = True
if(ar == [False] * (n + 1)):
	if(n == 1):
		print(0)
	else:
		print(1)
else:
	ones = 0
	zeros = 0
	for x in range(1, n + 1):
		if(not ar[x]):
			if(x % 2 == 0):
				zeros+=1
			else:
				ones += 1

	c = 0
	for x in range(1, n):
		if(p[x] != 0 and p[x - 1] != 0 and p[x] % 2 != p[x - 1] % 2):
			c += 1
	s = 0
	for x in range(n):
		if(p[x] != 0):
			s = x
			break
	c1 = 0
	s1 = -1
	zerosp = []
	onesp = []
	c1 = 0
	for x in range(s + 1, n):
		if(p[x] == 0):
			if(s1 == -1):
				s1 = x
			c1 += 1
		elif(c1 != 0):
			if(p[s1 - 1] % 2 != p[x] % 2):
				c += 1
			else:
				if(p[s1 - 1] % 2 == 0):
					zerosp.append((c1, False))
				else:
					onesp.append((c1, False))
			s1 = -1
			c1 = 0
	if(n >= 2):
		if(p[0] == 0):
			if(p[s] % 2 == 0):
				zerosp.append((s, True))
			else:
				onesp.append((s, True))
		if(p[-1] == 0):
			c1 = 0
			s2 = 0
			for x in range(n - 2, -1, -1):
				c1 += 1
				if(p[x] != 0):
					s2 = x
					break
			if(p[s2] % 2 == 0):
				zerosp.append((c1, True))
			else:
				onesp.append((c1, True))
	c1 = 0
	zerosp = sorted(zerosp, key=lambda x: x[0])
	onesp = sorted(onesp, key=lambda x: x[0])
	print(c + calculate(zerosp, zeros) + calculate(onesp, ones))

				
