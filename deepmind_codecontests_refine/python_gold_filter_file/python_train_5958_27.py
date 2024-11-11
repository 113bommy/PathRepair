import math

T = int(input())
for _ in range(T):
	n, g, b = map(int, input().split(' '))
	goodtiles = math.ceil(n / 2)
	
	
	daysneeded = (g + b) * (goodtiles // g)
	#print('daysneed',daysneeded)
	
	
	
	if goodtiles % g != 0:
		print(max(n, daysneeded + goodtiles % g))
	
	elif goodtiles % g == 0:
		print(max(n, daysneeded - b))
