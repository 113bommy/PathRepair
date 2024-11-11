import math

requirePopulation = 1000000

n, s = map(int, input().split())

locations = {}
for i in range(n):
	x, y, k = map(int, input().split())
	key = round(math.sqrt(abs(x) * abs(x) + abs(y) * abs(y)), 7)
	if key in locations:
		locations[key] += k
	else:
		locations[key] = k

totalBonus = 0
for i in sorted (locations.keys()):
	totalBonus += locations[i]
	if s + totalBonus >= requirePopulation:
		print(i)
		exit()
print(-1)
