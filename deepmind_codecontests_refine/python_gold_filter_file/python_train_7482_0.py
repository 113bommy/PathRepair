import math
while True:
	d,w,h = map(int,input().split())
	if d == 0:
		break
	n = int(input())
	dist = [math.sqrt(d**2+w**2), math.sqrt(d**2+h**2), math.sqrt(w**2+h**2)]
	leng = min(dist)
	for i in range(n):
		if 2*int(input())-leng > 0:
			print('OK')
		else:
			print('NA')