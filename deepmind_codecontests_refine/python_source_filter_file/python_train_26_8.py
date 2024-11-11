r1 ,r2 = map(int,input().split())
c1,c2 = map(int,input().split())
d1 , d2 = map(int,input().split())
for a1 in range(1 , 10):
	for a2 in range(1,10):
		for a3 in range(1,10):
			for a4 in range(1 ,10):
				if a1 == a2 or a1 == a3 or a1 == a4 or a2 == a3 or a2 == a4 or a3 == 4:
					pass
				elif a1 + a2 == r1 and a3 + a4 == r2 and a1 + a4 == d1 and a1 + a3 == c1 and a2 + a4 == c2 and a2 + a3 == d2:
					print(a1,a2)
					print(a3,a4)
					exit()
print(-1)
