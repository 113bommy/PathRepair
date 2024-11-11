import re

t = int( input() )
for z in range(t):
	n = int( input() )
	users = input().split();
	#print(users)
	m = int( input() )
	can = [ [] for i in range(m) ]
	ok = True
	L = []
	for i in range(m):
		l = input().split(':')
		#print(l)
		L += [l]
		if l[0] != '?':
			can[i] = [users.index(l[0])]
		else:
			can[i] = [x for x in range(n)]
		ll = re.sub(r'[^A-Za-z0-9]', ' ', l[1]).split()
		for j in ll:
			print(j)
			if j in users:
				try:
					can[i].remove( users.index(j) )
				except ValueError:
					pass
		if len(can[i]) == 0:
			ok = False
	if ok == False:
		print('Impossible')
		continue
	while 1:
		flag = True
		for i in range(m - 1):
			if (len(can[i]) == 0): ok = False
			if (len(can[i]) == 1 and can[i][0] in can[i+1]):
				can[i+1].remove( can[i][0] )
				L[i][0] = users[ can[i][0] ]
				flag = False
			if (len(can[i + 1]) == 1 and can[i + 1][0] in can[i]):
				can[i].remove( can[i + 1][0] )
				L[i + 1][0] = users[ can[i + 1][0] ]
				flag = False
		if len(can[m - 1]) == 0: ok = False
		if ok == False: break
		if flag: break
	if ok == False:
		print('Impossible')
		continue
	for i in range(m):
		if L[i][0] == '?':
			print(users[ can[i][0] ], end='')
			if i < m - 1 and can[i][0] in can[i + 1]:
				can[i + 1].remove( can[i][0] )
		else:
			print(L[i][0], end='')
		print(':', L[i][1], sep = '');
