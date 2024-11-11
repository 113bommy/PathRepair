def find_color(room, color):
	for i, line in enumerate(room):
		j = line.find(color)
		if j != -1:
			return (i, j)

inp = input().split()
height, width = [int(i) for i in inp[:2]]
color = inp[2]
room = []

for i in range(height):
	room.append(input())

y, x = find_color(room, color)

adyacents = set()

i = x
j = y

#print(i, j)

while i < width and room[y][i] == color:
#	print(f"checking {(y - 1, i)}: {room[y - 1][i]}")
	if y > 0:
		adyacents.add(room[y - 1][i])
	i += 1

while j < height and room[j][x] == color:
	#print(f"checking {(j, x - 1)}: {room[j][x - 1]}")
	if x > 0:
		adyacents.add(room[j][x - 1])
	j += 1

#print(i, j)
if i < width:
	i -= 1
	while y < height and room[y][i] == color:
		#print(f"checking {(y, i + 1)}: {room[y - 1][i]}")
		adyacents.add(room[y][i + 1])
		y += 1

if j < height:
	j -= 1
	while x < width and room[j][x] == color:
		#print(f"checking {(j + 1, x)}: {room[j + 1][x]}")
		adyacents.add(room[j + 1][x])
		x += 1

#print(adyacents)
result = len(adyacents)
if '.' in adyacents:
	result -= 1
if color in adyacents:
	result -= 1
print(result)