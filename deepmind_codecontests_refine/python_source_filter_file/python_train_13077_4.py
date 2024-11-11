a,b = map(int,input().split())
if b-a>10:
	print("0")
elif a == b:
	print("1")
else:
	a = str(a)
	b = str(b)
	a = a[len(a)-1]
	b = b[len(b)-1]
	a = int(a)
	b = int(b)
	fact = 1
	if a == 0 and b == 0:
		print("0")
	else:
		if a>b:
			if b == 0:
				b = 10
			if b == 1:
				b = 11
			if b == 2:
				b = 12
			if b == 3:
				b = 13
			if b == 4:
				b = 14
			if b == 5:
				b = 15
			if b == 6:
				b = 16
			if b == 7:
				b = 17
			if b == 8:
				b = 18
			if b == 9:
				b = 19
		for i in range(b, a, -1):
			fact = fact * i
		fact = str(fact)
		fact = fact[len(fact)-1]
		print(fact)