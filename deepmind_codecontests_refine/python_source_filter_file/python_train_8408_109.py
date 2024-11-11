x = int(input())
d = dict()
for i in range(-100, 101):
	d[i**5] = i
for i in d:
	if x+i in d:
		print(d[i], d[x+i])
		break
