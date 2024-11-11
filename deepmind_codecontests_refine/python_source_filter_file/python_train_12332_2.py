a = list(map(int,input().split()))
b = ["S", "M", "L", "XL", "XXL"]
for _ in range(int(input())):
	s = input()
	if s == "S":
		for x in range(5):
			if a[x] != 0:
				a[x] -= 1
				print(b[x])
				break
	elif len(s) == 3:
		for x in range(4, -1, -1):
			if a[x] != 0:
				a[x] -= 1
				print(b[x])
				break
	else:
		c = b.index(s)
		if a[c] != 0:
			a[c] -= 1
			print(a[c])
		else:
			d = 1
			for x in range(5):
				if (c + d) < 5 and a[c + d] > 0 :
					a[c + d] -= 1
					print(b[c + d])
					break
				elif a[c - d] >= 0 and (c - d) >= 0:
					a[c - d] -= 1
					print(b[c - d])
					break
				else:d += 1
