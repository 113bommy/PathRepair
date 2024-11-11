t = int(input())
for x in range(t):
	b, p, f = map(int, input().split())
	h, c = map(int, input().split())
	money = 0
	if h > c:
		while b >= 2 and p >= 1:
			money+= h
			b-= 2
			p-= 1
		while b >= 2 and f >= 1:
			money+= c
			b-= 2
			f-= 1
	else:
		while b >= 2 and f >= 1:
			money+= c
			b-= 2
			f-= 1
		while b >= 2 and p >= 1:
			money+= h
			b-= 2
			p-= 1
		print(money)





