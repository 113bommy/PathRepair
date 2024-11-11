# Bismillah
# In the name of GOD

for _ in range(int(input())):
	n, x = map(int, input().split())
	a = list(map(int, input().split()))
	values = [False] * 201
	for value in a:
		values[value - 1] = True
	for i in range(201):
		if values[i] == True:
			continue
		values[i] = True
		x -= 1
		if x < 1:
			break
	for i in range(201):
		if values[i] == False:
			print(i)
			break
