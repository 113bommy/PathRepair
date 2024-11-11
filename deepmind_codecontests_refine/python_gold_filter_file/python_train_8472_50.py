x = input()
x = x.split()
x = [int(i) for i in x]

a, b = x

h = (a + 1) // 2

if b <= h:
	print(b * 2 - 1)
else:
	print((b - h) * 2)

