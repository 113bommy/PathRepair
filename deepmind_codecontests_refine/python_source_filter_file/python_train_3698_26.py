input()
cards = list(input())
r, g, b = 0, 0, 0
for card in cards:
	if card == 'R':
		r += 1
	elif card == 'G':
		g += 1
	else:
		b += 1
if (r == 0 and g == 0) or (r,g,b) == (1,1,0):
	print('B')
elif (r == 0 and b == 0) or (r,g,b) == (1,0,1):
	print('G')
elif (b == 0 and g == 0) or (r,g,b) == (0,1,1):
	print('R')
elif (r,g,b) == (1,2,0) or (r,g,b) == (0,2,1):
	print('BR')
elif (r,g,b) == (2,1,0) or (r,g,b) == (2,0,1):
	print('BG')
elif (r,g,b) == (1,0,2) or (r,g,b) == (0,1,2):
	print('GR')
else:
	print('BGR')