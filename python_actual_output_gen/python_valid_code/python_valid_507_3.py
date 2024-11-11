t = int(input())
otv = list()
for i in range(t):
	n = input()
	sp = list()
	for j in n:
		if sp.count(j) < 3:
			sp.append(j)
	otv.append(len(sp) // 2)
for i in otv:
	print(i)
