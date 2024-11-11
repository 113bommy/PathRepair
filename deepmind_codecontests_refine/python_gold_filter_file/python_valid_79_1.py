def is_easy(x):
	d = int(x ** 0.5)
	for j in range(2, d + 1):
		if x % j == 0:
			return False
	return True


for _ in range(int(input())):
	k = int(input())
	s = input()
	d = "14689"
	f = False
	for i in d:
		if i in s:
			print(1)
			print(i)
			f = True
			break
	if f:
		continue
	for i in range(k):
		for j in range(i + 1, k):
			d = int(s[i]) * 10 + int(s[j])
			if not(is_easy(d)):
				print(2)
				print(d)
				f = True
				break
		if f:
			break
	if f:
		continue
	for i in range(k):
		for j in range(i + 1, k):
			for z in range(j + 1, k):
				d = int(s[i]) * 100 + int(s[j]) * 10 + s[z]
				if not(is_easy(d)):
					print(3)
					print(d)
					f = True
					break
			if f:
				break
		if f:
			break
