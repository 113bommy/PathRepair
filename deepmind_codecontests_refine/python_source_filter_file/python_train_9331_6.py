y , b = map(int, input().split())
y1, g1, b1 = map(int, input().split())
yell = y1*2 + g1
blue = b1*3 + g1
if yell > y and blue > b:
	print(yell - y + blue - b)
elif yell > y:
	print(yell - y1)
elif blue > b:
	print(blue - b)
else:
	print(0)
