import sys
	
lines = iter(sys.stdin.read().splitlines())

next(lines)

s,d = map(int,next(lines).split())

dates = [[0,0],[s, s + d -1],[1000000001,1000000001]]
res = [[s, s + d -1]]

for line in lines:
	s,d = map(int,line.split())
	
	nhueco = True
	
	for i in range(len(dates)):
		if s > dates[i][1] and s+d-1 < dates[i+1][0]:
			dates.insert(i+1,[s, s + d -1])
			res.append([s, s + d -1])
			break
		elif nhueco and dates[i][1] + dates[i+1][0] -1 >= d:
			nhueco = False
			ld = dates[i][1] + 1
			li = i+1
	else:
		dates.insert(li,[ld, ld + d -1])
		res.append([ld, ld + d -1])

for date in res:
	print(" ".join(map(str,date)))
