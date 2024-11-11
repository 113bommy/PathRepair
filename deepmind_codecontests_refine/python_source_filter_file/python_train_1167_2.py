t = int(input())

right = 'R'
up = 'U'

for i in range(0, t):
	n = int(input())
	b = True
	l = []
	
	for j in range(0, n):
		x, y = map(int, input().split())
		l.append([x, y])
		
	l.sort()
	res = ""
	pos = [0, 0]
	for e in l:
		while e[1] > pos[1]:
			res += "R"
			pos[1] += 1
		while e[0] > pos[0]:
			res += "U"
			pos[0] += 1
		if e[0] != pos[0] or e[1] != pos[1]:
			b = False
		
	if b:
		print("YES")
		print(res)
	else:
		print("NO")
			
			
			
	
		
	
	
	
	
