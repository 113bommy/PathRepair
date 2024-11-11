t = input()
t = t.split()
a = int(t[0])
b = int(t[1])
n = int(t[2])
fail = False
for i in range(n):
	a *= 10
	temp = -1
	for j in range(10):
		if ((a + j) % b == 0):
			temp = j
			break
	if (temp == -1):
		fail = True
		break
	else:
		a += temp
		break
if (fail):
	print("-1")
else:
	x = ""
	l = len(str(a))
	for i in range(n - l + 1):
		x += "0"
	print(str(a) + x)