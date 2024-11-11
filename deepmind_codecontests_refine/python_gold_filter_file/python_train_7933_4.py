a=list(input() for i in range(8))
ok1=list()
ok2=set()
ok1.append((7,0))
w=[(1,0),(-1,0),(0,1),(0,-1),(1,-1),(1,1),(-1,-1),(-1,1),(0,0)]
for i in range(8) :
	for pos in ok1 :
		if pos[0]>=i and a[pos[0]-i][pos[1]] == 'S' :
			continue 
		for j in w:
			to=(pos[0]+j[0],pos[1]+j[1])
			if to[0]<8 and to[1]<8 and to[0]>-1 and to[1]>-1:
				if to[0]<i or a[to[0]-i][to[1]] != 'S' :
					ok2.add(to)
	ok1.clear()
	ok1=list(ok2.copy())
	ok2.clear()
print("WIN" if len(ok1)>0 else "LOSE")