x = int(input())
d = dict()
for i in range(-200, 201):
	d[i**5] = i
for i in d:
	if x+i in d:
		print(d[x+i], d[i])
		break
