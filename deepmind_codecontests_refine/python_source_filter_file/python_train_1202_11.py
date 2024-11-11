a = input()

x = 0
y = 0

for i in a:
	if i == "U":
		x += 1
	elif i == "D":
		x -= 1
	elif i == "R":
		y += 1
	else:
		y -= 1

x = abs(x)
y = abs(y)

printar = 0

while x > 0 and y > 0:
  printar += 1
  x -= 1
  y -= 1

if x == 0 and y == 0:
  print(printar)
elif x % 2 == 0 and y % 2 == 0:
	printar += x/2 + y/2
	print(printar)
else:
	print(-1)