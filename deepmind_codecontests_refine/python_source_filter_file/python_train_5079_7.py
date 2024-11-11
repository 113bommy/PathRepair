n, d, a = map(int, input().split())

D = True

pos = []
pos1 = []

for i in range(n):
	x, h = map(int, input().split())
	pos.append((x, h))

pos.sort(key=lambda x: x[0])

bombs = 0
damage = 0
y, z = 0, 0


while y < n:
	x0 = pos[y][0]
	try:
		x1 = pos1[z][0]
	except IndexError:
		x1 = 1e16
	if x0 <= x1:
		health = pos[y][1]
		health -= damage
		number = (health-1) // a + 1
		bombs += number
		damage += number*a
		pos1.append((x0+2*d, number*a))
		y+=1
	else:
		damage -= pos1[z][1]
		z += 1
	

print(bombs)

