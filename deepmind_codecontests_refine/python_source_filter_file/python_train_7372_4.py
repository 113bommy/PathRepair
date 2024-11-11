a,b = map(int,input().split())

c = []

for i in range(a):
	c.append(list(map(int,input().split())))

ans = float('inf')

for i in range(1<<a):
	sc = 0
	co = 0
	for j in range(a):
		if i & (1<<j):
			sc += c[j][0]*(j+1)*100 + c[j][1]
			co += c[j][0]
	if sc >= b:
		ans = min(ans,co)
	else:
		for j in range(a)[::-1]:
			if i &(1<<j):
				continue
			else:
				for k in range(c[j][0]):
					sc += 100*(j+1)
					co += 1
					if sc >= b:
						break
				if sc >= b:
					break
		ans = min(ans,sc)

print(ans)
