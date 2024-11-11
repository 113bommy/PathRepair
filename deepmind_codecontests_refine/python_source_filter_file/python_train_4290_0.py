from sys import stdin
input = stdin.readline
q = int(input())
for rwre in range(q):
	n, s = map(int,input().split())
	przed = [list(map(int,input().split())) for i in range(n)]
	przed.sort()
	przed.reverse()
	l = 1
	p = 10 ** 9
	while abs(p - l) > 1:
		mozna = 1
		sr = (p + l + 1) // 2
		#try to make median >= sr
		duze = [przed[i] for i in range(n) if przed[i][1] >= sr ]
		male = [przed[i] for i in range(n) if przed[i][1] < sr ]
		if len(duze) <= n // 2:
			mozna = 0
		else:
			spent = 0
			dudes = 0
			for i in range(n//2 + 1):
				spent += max(sr, duze[i][0])
			dudes = n//2 + 1
			duze = duze[(n//2+1):]
			for du in duze:
				spent += du[0]
			for ma in male:
				spent += ma[0]
			if spent > s:
				mozna = 0
		if mozna == 1:
			l = sr
		else:
			p = sr - 1
	print((p+l)//2)
						
					
				
		