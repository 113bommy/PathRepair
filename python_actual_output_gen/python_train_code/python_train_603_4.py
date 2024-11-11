t = int(input())

for _ in range(t):
	x,y = map(int,input().split())
	ans  = 0
	flag = 0

	if x > y:
		while x > y:
			if (x//8)%y == 0:
				x = x//8
			elif (x//4)%y == 0:
				x = x//4
			elif (x//2)%y == 0:
				x = x//2
			else:
				break
			ans += 1
	elif x < y:
		while x < y:
			if y%(x*8) == 0:
				x = x*8
			elif y%(x*4) == 0:
				x = x*4
			elif y%(x*2) == 0:
				x = x*2
			else:
				break
			ans += 1

	if x == y:	print(ans)
	else:	print(-1)	