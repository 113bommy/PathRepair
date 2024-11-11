r, c, n, k = map(int, input().split(' '))
p = []

def findIn(z, x, y, s):
	global n
	ret = 0
	for i in range(n):
		if z <= p[i][0] and y >= p[i][0] and x <= p[i][1] and s >= p[i][1]:
			ret = ret + 1
	return ret

for i in range(n):
	x, y = map(int, input().split(' '))
	p.append((x, y))

ans = 0
for z in range(1, c + 1):
	for x in range(1, r + 1):
		for y in range(z, c + 1):
			for s in range(x, r + 1):
				if findIn(z, x, y, s) >= k:
					ans = ans + 1
print (ans);
				

	
