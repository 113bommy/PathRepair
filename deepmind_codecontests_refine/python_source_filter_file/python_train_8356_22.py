t = int(input())

for i in range(t):

	n = int(input())

	if n in [1,2,4,6]:
		print(-1)
	else:
		if n == 3:
			print(1,0,0)
		elif n == 5:
			print(0,1,0)
		elif n == 7:
			print(0,0,1)
		else:
			if n%5 == 0:
				print(0,n//5,0)
			elif n%7 == 0:
				print(0,0,n//7)
			elif n%3 == 0:
				print(n//3, 0, 0)
			else:
				if n%3 == 2:
					n-=5
					print(n//3, 1, 0)
				else:
					n -= 7
					print(n//3, 0, 1)